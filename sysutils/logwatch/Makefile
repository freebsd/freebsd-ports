# Created by: John D. "Trix" Farrar <trix@basement.net>
# $FreeBSD$

PORTNAME=	logwatch
PORTVERSION=	7.4.0
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	trix@basement.net
COMMENT=	Log file analysis program

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-MIME-Base64>=0:${PORTSDIR}/converters/p5-MIME-Base64

USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	scripts/logwatch.pl
PORTDOCS=	HOWTO-Customize-LogWatch README
NO_BUILD=	yes
MAKE_ENV+=	SITE_PERL_REL=${SITE_PERL_REL}
OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

pre-configure:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-patch:
	${REINPLACE_CMD}  -E \
	-e "s,/usr/share/logwatch,${LOCALBASE}," \
	-e "s,/etc/logwatch,${ETCDIR}," \
	-e 's,^eval "use lib.*,,' \
	-e "s,.BaseDir/lib,${LIBEXECDIR}," \
	-e 's,BaseDir/dist.conf,ConfigDir/defaults,' \
	-e 's,BaseDir/default.conf,ConfigDir/defaults,' \
	-e 's,ConfigDir/conf,ConfigDir,' \
	-e "s,BaseDir/scripts/([^/]*)/,BaseDir/libexec/${PORTNAME}/defaults/\1/," \
	-e "s,ConfigDir/scripts/([^/]*)/,BaseDir/libexec/${PORTNAME}/\1/," \
	${WRKSRC}/scripts/logwatch.pl
	${REINPLACE_CMD}  -E \
	-e "s,/var/cache/logwatch,${LOCALBASE}/var/${PORTNAME}," \
	${WRKSRC}/conf/logwatch.conf

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/HOWTO-Customize-LogWatch ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
