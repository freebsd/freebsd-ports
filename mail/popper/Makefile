# New ports collection makefile for:	popper
# Date created:		1 April 1995
# Whom:			pst
#
# $FreeBSD$
#

PORTNAME=	qpopper
PORTVERSION=	2.53
PORTREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.qualcomm.com/eudora/servers/unix/popper/old/
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ache@freebsd.org
COMMENT=	Berkeley POP 3 server (now maintained by Qualcomm)

# Set WITH_POPPER_YOUBIN_SUPPORT variable in the environment to enable
# youbin support.
#
# If WITH_POPPER_APOP_ONLY variable present in the environment, popper builds
# with APOP authentification only.
#
# If WITH_POPPER_DEBUG variable present in the environment, popper builds
# with more verbose debugging.

O_DEFS=		-DSETPROCTITLE -DKEEP_TEMP_DROP -DBSD44_DBM -DBIND43 \
		-DBULLDB -DNONAUTHFILE='\"/etc/ftpusers\"'

.if !defined(WITH_POPPER_APOP_ONLY)
P_LIBS=		-lopie
O_DEFS+=	-DOPIE
.else
O_DEFS+=	-DAPOP_ONLY
.endif

.if defined(WITH_POPPER_YOUBIN_SUPPORT)
O_DEFS+=	-DYOUBIN -DCALLED_FROM_POPD
.endif

P_LIBS+=	-lmd -lutil

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-apop=${PREFIX}/etc/popper/pop.auth \
		--with-apopuid=pop
.if defined(WITH_POPPER_DEBUG)
CONFIGURE_ARGS+=	--enable-debugging
.endif
CONFIGURE_ENV=	LIBS="${P_LIBS}" O_DEFS="${O_DEFS}"

MAN8=	popauth.8 popper.8
PLIST_FILES=	bin/popauth libexec/popper
PLIST_DIRS=	etc/popper

LATEST_LINK=	popper

PORTSCOUT=      limit:^2\.

post-patch:
	$(RM) ${WRKSRC}/md5.h
	$(CP) ${FILESDIR}/sendto.c ${WRKSRC}

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} -o pop -m 4111 popauth ${PREFIX}/bin
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} popper ${PREFIX}/libexec
	cd ${WRKSRC} && \
		${INSTALL_MAN} ${MAN8} ${PREFIX}/man/man8

.include <bsd.port.mk>
