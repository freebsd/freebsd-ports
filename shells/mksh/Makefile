# Created by: Andreas Kohn <andreas@syndrom23.de>
# $FreeBSD$

PORTNAME=	mksh
DISTVERSION=	R41
CATEGORIES=	shells
MASTER_SITES=	http://www.mirbsd.org/MirOS/dist/mir/mksh/ \
		http://pub.allbsd.org/MirOS/dist/mir/mksh/
DISTFILES=	${PORTNAME}-${DISTVERSION}.tgz

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A MirBSD enhanced shell based on pdksh

WRKSRC=		${WRKDIR}/${PORTNAME}

MAN1=		mksh.1

.include <bsd.port.pre.mk>

do-build:
	cd ${WRKSRC} && CFLAGS="${CFLAGS}" CC="${CC}" LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}" SHELL=${SH} ${SH} ${WRKSRC}/Build.sh -r -c lto

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mksh ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mksh.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/dot.mkshrc ${EXAMPLESDIR}
.endif

post-install:
	@${ECHO_MSG} "updating /etc/shells"
	@${CP} /etc/shells /etc/shells.bak
	@(${GREP} -v ${PREFIX}/bin/mksh /etc/shells.bak; \
	${ECHO_CMD} ${PREFIX}/bin/mksh) > /etc/shells
	@${RM} /etc/shells.bak

.include <bsd.port.post.mk>
