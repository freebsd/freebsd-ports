# $FreeBSD$

PORTNAME=	keyboard-daemon
PORTVERSION=	0.7
CATEGORIES=	sysutils
MASTER_SITES=	http://www.bayofrum.net/dist/${PORTNAME}/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Listens on a keyboard device and executes commands on keypresses

LICENSE=	BSD

BUILD_DEPENDS=	${LOCALBASE}/lib/libcfu.a:${PORTSDIR}/devel/libcfu

USE_BZIP2=	yes

USE_RC_SUBR=	${PORTNAME:S/-/_/}
PLIST_FILES=	bin/${PORTNAME}
PORTEXAMPLES=	*
MAN1=		${PORTNAME}.1
MANCOMPRESSED=	yes

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1.gz ${MAN1PREFIX}/man/man1/
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	for f in ${WRKSRC}/examples/*; do	\
	    ${INSTALL_DATA} $$f ${EXAMPLESDIR};	\
	done
.endif

.include <bsd.port.mk>
