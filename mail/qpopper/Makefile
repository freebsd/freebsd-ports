# New ports collection makefile for:	popper 3.*
# Date created:		1 April 1995
# Whom:			pst
#
# $FreeBSD$
#

PORTNAME=	qpopper3
PORTVERSION=	3.0.2
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.qualcomm.com/eudora/servers/unix/popper/
DISTNAME=	qpopper${PORTVERSION}

MAINTAINER=	jeff@isni.net

# If APOP_ONLY variable present in the environment, popper builds
# with APOP authentification only.
#
# If FULL_POPD_DEBUG variable present in the environment, popper builds
# with more verbose debugging.

OS_DEFS=	-DSETPROCTITLE -DKEEP_TEMP_DROP -DBSD44_DBM \
		-DNONAUTHFILE='\"/etc/ftpusers\"'

.if defined(APOP_ONLY)
OS_DEFS+=	-DAPOP_ONLY
.endif

P_LIBS+=	-lmd -lutil

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-apop=${PREFIX}/etc/popper/pop.auth \
		--with-apopuid=pop
.if defined(FULL_POPD_DEBUG)
CONFIGURE_ARGS+=--enable-debugging
.endif
CONFIGURE_ENV=	LIBS="${P_LIBS}" OS_DEFS="${OS_DEFS}"

MAN8=		popauth3.8 popper3.8

post-patch:
	@$(RM) -f ${WRKSRC}/popper/md5.h

do-install:
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} popper/popauth ${PREFIX}/bin/popauth3 && \
		${INSTALL_PROGRAM} popper/popper ${PREFIX}/libexec/popper3 && \
		${INSTALL_MAN} man/popauth.8 ${PREFIX}/man/man8/popauth3.8 && \
		${INSTALL_MAN} man/popper.8 ${PREFIX}/man/man8/popper3.8

.include <bsd.port.mk>
