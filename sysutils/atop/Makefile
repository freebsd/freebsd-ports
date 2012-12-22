# Created by: Alex Samorukov <samm@os2.kiev.ua>
# $FreeBSD$

PORTNAME=	atop
PORTVERSION=	2.0.2.b2
CATEGORIES=	sysutils

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	ASCII Monitor for system resources and process activity

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	samm-git
GH_PROJECT=	atop-freebsd
GH_TAGNAME=	${PORTNAME}-${PORTVERSION:C|b|fbsd.beta|}
GH_COMMIT=	f9357ca

USE_NCURSES=	yes
MAKEFILE=	BSDmakefile
MAN1=		atop.1 atopsar.1
MAN5=		atoprc.5
LOGDIR?=	/var/log/atop

USE_RC_SUBR=	atop
PLIST_SUB+=	LOGDIR="${LOGDIR}"
SUB_FILES=	pkg-message
SUB_LIST=	LOGDIR="${LOGDIR}"

PORTDOCS=	AUTHOR \
		ChangeLog \
		ChangeLog.FreeBSD \
		README \
		README.FreeBSD

do-install:
		@${INSTALL_PROGRAM} ${WRKSRC}/atop ${PREFIX}/bin
		@${LN} -sf ${PREFIX}/bin/atop ${PREFIX}/bin/atopsar
.for manpage in ${MAN1}
		@${INSTALL_MAN} ${WRKSRC}/man/${manpage} ${MAN1PREFIX}/man/man1/
.endfor
		@${INSTALL_MAN} ${WRKSRC}/man/${MAN5} ${MAN5PREFIX}/man/man5/
		@${MKDIR} ${LOGDIR}
.if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
		${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
