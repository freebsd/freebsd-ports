# New ports collection makefile for:	popper
# Date created:		1 April 1995
# Whom:			pst
#
# $FreeBSD$
#

PORTNAME=	qpopper
PORTVERSION=	2.53
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.qualcomm.com/eudora/servers/unix/popper/old/
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ache@freebsd.org

# Set POPD_YOUBIN_SUPPORT variable in the environment to enable
# youbin support.
#
# If APOP_ONLY variable present in the environment, popper builds
# with APOP authentification only.
#
# If FULL_POPD_DEBUG variable present in the environment, popper builds
# with more verbose debugging.

O_DEFS=		-DSETPROCTITLE -DKEEP_TEMP_DROP -DBSD44_DBM -DBIND43 \
		-DBULLDB -DNONAUTHFILE='\"/etc/ftpusers\"'

.if !defined(APOP_ONLY)
.if exists(/usr/lib/libskey.a)
P_LIBS=		-lskey
O_DEFS+=	-DSKEY
.endif
.else
O_DEFS+=	-DAPOP_ONLY
.endif

.if defined(POPD_YOUBIN_SUPPORT)
O_DEFS+=	-DYOUBIN -DCALLED_FROM_POPD
.endif

P_LIBS+=	-lmd -lutil

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-apop=${PREFIX}/etc/popper/pop.auth \
		--with-apopuid=pop
.if defined(FULL_POPD_DEBUG)
CONFIGURE_ARGS+=	--enable-debugging
.endif
CONFIGURE_ENV=	LIBS="${P_LIBS}" O_DEFS="${O_DEFS}"

MAN8=	popauth.8 popper.8

post-patch:
	$(RM) ${WRKSRC}/md5.h
	$(CP) ${FILESDIR}/sendto.c ${WRKSRC}

do-install:
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} -o pop -m 4111 popauth ${PREFIX}/bin
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} popper ${PREFIX}/libexec
	cd ${WRKSRC} && \
		${INSTALL_MAN} ${MAN8} ${PREFIX}/man/man8

.include <bsd.port.mk>
