PORTNAME=	atop
PORTVERSION=	2.0.2.b3
PORTREVISION=	4
CATEGORIES=	sysutils

MAINTAINER=	samm@FreeBSD.org
COMMENT=	ASCII Monitor for system resources and process activity
WWW=		https://github.com/samm-git/atop-freebsd

LICENSE=	GPLv2

USES=		ncurses

USE_GITHUB=	yes
GH_ACCOUNT=	samm-git
GH_PROJECT=	atop-freebsd
GH_TAGNAME=	${PORTNAME}-${PORTVERSION:C|b|fbsd.beta|}

MAKEFILE=	BSDmakefile
LOGDIR?=	/var/log/atop
PLIST_SUB+=	LOGDIR="${LOGDIR}"
SUB_LIST=	LOGDIR="${LOGDIR}"

USE_RC_SUBR=	atop
SUB_FILES=	pkg-message

PORTDOCS=	AUTHOR \
		ChangeLog \
		ChangeLog.FreeBSD \
		README \
		README.FreeBSD

OPTIONS_DEFINE=	DOCS

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/atop ${STAGEDIR}${PREFIX}/bin
		${LN} -sf atop ${STAGEDIR}${PREFIX}/bin/atopsar
.for manpage in atop.1 atopsar.1
		${INSTALL_MAN} ${WRKSRC}/man/${manpage} ${STAGEDIR}${PREFIX}/share/man/man1/
.endfor
		${INSTALL_MAN} ${WRKSRC}/man/atoprc.5 ${STAGEDIR}${PREFIX}/share/man/man5/
		@${MKDIR} ${STAGEDIR}${LOGDIR}
		@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
		${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
