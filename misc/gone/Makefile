# New ports collection makefile for:   gone
# Version required:    1.3
# Date created:        19 April 1998
# Whom:                marcus
#
# $Id: Makefile,v 1.2 1998/04/20 03:17:26 mph Exp $
#

DISTNAME=       gone-1.3
CATEGORIES=     misc
MASTER_SITES=   http://jaguar.ir.miami.edu/~marcus/

MAINTAINER=     marcus@miami.edu

GNU_CONFIGURE=  yes

MAN1=		gone.1

.if !defined(WITH_SETUID)
WITH_SETUID=	no
CONFIGURE_ENV=	SETUID_Q=no
SHOWHELP=	yes
.elif ${WITH_SETUID} == YES || ${WITH_SETUID} == yes || ${WITH_SETUID} == Yes
CONFIGURE_ENV=	SETUID_Q=yes
.elif ${WITH_SETUID} == NO || ${WITH_SETUID} == no || ${WITH_SETUID} == No
CONFIGURE_ENV=	SETUID_Q=no
.else
ABORT=		yes
.endif

pre-configure:
.if defined(SHOWHELP)
	@ ${ECHO_MSG} To authenticate system passwords, build with \"make WITH_SETUID=YES\".
	@ ${ECHO_MSG} Running setuid could introduce security holes in your system.
.endif
.if defined(ABORT)
	@ ${ECHO_MSG} I do not understand WITH_SETUID=${WITH_SETUID}.  Set to YES or NO.
	@ ${FALSE}
.endif

.include <bsd.port.mk>
