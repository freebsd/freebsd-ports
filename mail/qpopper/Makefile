# New ports collection makefile for:	qpopper 3.1.b5
# Date created:				Di  18 Jul 2000 22:36:34 CEST
# Whom:					alex
#
# $FreeBSD$
#

PORTNAME=	qpopper
PORTVERSION= 	3.1.b5
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.qualcomm.com/eudora/servers/unix/popper/beta/
DISTNAME=	${PORTNAME}3.1b5

MAINTAINER=	ports@freebsd.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-apop=${PREFIX}/etc/popper/pop.auth

O_DEFS=         -DSETPROCTITLE -DKEEP_TEMP_DROP -DBSD44_DBM -DBIND43 \
		-DBULLDB -DNONAUTHFILE='\"/etc/ftpusers\"'
P_LIBS+=        -lmd -lutil

# Set FULL_POPD_DEBUG for debug-mode. See also -d option to popper
.if defined(FULL_POPD_DEBUG)
CONFIGURE_ARGS+=--enable-debugging
.endif

CONFIGURE_ENV=	LIBS="${P_LIBS}" O_DEFS="${O_DEFS}"

MAN8=		popauth.8 popper.8

do-install:
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} popper/popauth ${PREFIX}/bin
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} popper/popper ${PREFIX}/libexec
	cd ${WRKSRC} && \
		${INSTALL_MAN} man/popauth.8 man/popper.8 ${PREFIX}/man/man8

post-install:
	@${SED} -e "s:/usr/local:${PREFIX}:" ${PKGMESSAGE}

.include <bsd.port.mk>
