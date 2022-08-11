PORTNAME=	flowd
PORTVERSION=	0.9.1
PORTREVISION=	4
CATEGORIES=	net-mgmt
MASTER_SITES=	http://mindrot.org/files/flowd/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Small, fast, and secure NetFlow collector

LICENSE=	MIT BSD2CLAUSE BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake shebangfix
SHEBANG_FILES=	tools/*.pl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var
USE_RC_SUBR=	flowd
PORTDOCS=	README INSTALL

FLOWD_USER=	_flowd

USERS=		${FLOWD_USER}
GROUPS=		${FLOWD_USER}

OPTIONS_DEFINE=	PERL DOCS EXAMPLES
OPTIONS_DEFAULT=PERL
OPTIONS_SUB=	yes

PERL_DESC=		Install flowd perl module
PERL_USES=		perl5

post-patch:
	@${REINPLACE_CMD} -e "s;%%FLOWD_USER%%;${FLOWD_USER};g" \
		${WRKSRC}/flowd.h

post-build-PERL-on:
	(cd ${WRKSRC}/Flowd-perl && ${PERL} Makefile.PL \
		INSTALLSITEMAN3DIR=${PERL5_MAN3} \
		DESTDIR=${STAGEDIR} PREFIX=${PREFIX} && \
		${MAKE_CMD})

pre-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

pre-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	( cd ${WRKSRC}/tools && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR} )

pre-install-PERL-on:
	( cd ${WRKSRC}/Flowd-perl && ${MAKE_CMD} install )
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Flowd/Flowd.so

.include <bsd.port.mk>
