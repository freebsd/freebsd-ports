# New ports collection makefile for:	popper
# Version required:     2.41beta1
# Date created:		1 April 1995
# Whom:			pst
#
# $Id: Makefile,v 1.21 1997/12/24 01:21:35 alex Exp $
#

DISTNAME=       qpopper2.41beta1
PKGNAME=        qpopper-2.41b1
CATEGORIES=	mail
MASTER_SITES=   ftp://ftp.qualcomm.com/eudora/servers/unix/popper/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ache@freebsd.org

#
# If APOP_ONLY variable present in the environment, popper builds
# with APOP authentification only
#

O_DEFS=         -DSETPROCTITLE -DKEEP_TEMP_DROP -DBSD44_DBM -DBIND43 \
		-DBULLDB -DNONAUTHFILE='\"/etc/ftpusers\"'

.if !defined(APOP_ONLY)
.if exists(/usr/lib/libskey.a)
P_LIBS=         -lskey
O_DEFS+=        -DSKEY
.endif
.else
O_DEFS+=        -DAPOP_ONLY
.endif

P_LIBS+=        -lmd -lutil

GNU_CONFIGURE=          yes
CONFIGURE_ARGS=         --with-apop=${PREFIX}/etc/popper/pop.auth \
			--with-apopuid=pop --enable-debugging
CONFIGURE_ENV=          LIBS="${P_LIBS}" O_DEFS="${O_DEFS}"

MAN8=   popauth.8 popper.8

post-patch:
	$(RM) ${WRKSRC}/md5.h

do-install:
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} -o pop -m 4111 popauth ${PREFIX}/bin
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} popper ${PREFIX}/libexec
	cd ${WRKSRC} && \
		${INSTALL_MAN} ${MAN8} ${PREFIX}/man/man8

.include <bsd.port.mk>
