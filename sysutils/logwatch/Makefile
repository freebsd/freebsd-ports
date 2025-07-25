PORTNAME=	logwatch
DISTVERSION=	7.13
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${DISTVERSION}

MAINTAINER=	trashcan@ellael.org
COMMENT=	Log file analysis program
WWW=		https://www.logwatch.org

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		perl5 shebangfix
USE_PERL5=	run

SHEBANG_FILES=	scripts/logwatch.pl

MAKE_ENV+=	SITE_PERL_REL=${SITE_PERL_REL}

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

PORTDOCS=	HOWTO-Customize-LogWatch README

OPTIONS_DEFINE=		DATEMANIP DOCS
DATEMANIP_DESC=		Install Date::Manip perl module for all valid --range parameters
DATEMANIP_RUN_DEPENDS=	p5-Date-Manip>=0:devel/p5-Date-Manip

pre-configure:
	${REINPLACE_CMD}  -E \
	-e "s,/usr/share/logwatch,${LOCALBASE}," \
	-e "s,/etc/logwatch,${ETCDIR}," \
	-e "s,.BaseDir/lib,${LIBEXECDIR}," \
	-e "s,BaseDir/scripts/([^/]*)/,BaseDir/libexec/${PORTNAME}/defaults/\1/," \
	-e "s,ConfigDir/scripts/([^/]*)/,BaseDir/libexec/${PORTNAME}/\1/," \
	${WRKSRC}/scripts/logwatch.pl
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/HOWTO-Customize-LogWatch ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
