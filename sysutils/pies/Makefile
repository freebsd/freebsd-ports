PORTNAME=	pies
PORTVERSION=	1.7
CATEGORIES=	sysutils
MASTER_SITES=	http://download.gnu.org.ua/pub/release/${PORTNAME}/ \
		http://download.gnu.org.ua/pub/alpha/${PORTNAME}/

MAINTAINER=	zeus@gnu.org.ua
COMMENT=	Program Invocation and Execution Supervisor

LICENSE=	GPLv3+

USES=		charsetfix gmake iconv tar:bz2
GNU_CONFIGURE=	yes
USE_RC_SUBR=	${PORTNAME}
TEST_TARGET=	check

INFO=		${PORTNAME}
PORTDOCS=	ChangeLog NEWS README

OPTIONS_DEFINE=	DOCS INETD NLS PAM
OPTIONS_SUB=	yes

INETD_DESC=	Build and install replacement for inetd(8)

INETD_CONFIGURE_ON=	--enable-inetd
NLS_USES=	gettext
NLS_CONFIGURE_OFF=	--disable-nls
PAM_CONFIGURE_OFF=	--disable-pam

post-patch:
	@${REINPLACE_CMD} -e '/abend\.at/d' ${WRKSRC}/grecs/tests/testsuite.at

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
