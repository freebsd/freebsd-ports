# New ports collection makefile for:   gone
# Version required:    1.3.1
# Date created:        19 April 1998
# Whom:                marcus
#
# $FreeBSD$
#

DISTNAME=       gone-1.3.1
CATEGORIES=     misc
MASTER_SITES=   http://jaguar.ir.miami.edu/~marcus/

MAINTAINER=     marcus@miami.edu

MAN1=		gone.1
GNU_CONFIGURE=  yes

#
# If you would like to be able to use system passwords for gone
# override this with WITH_SETUID=yes in your environment.
# Be aware that setting gone to suid MAY be a security hole.
#
WITH_SETUID?=	no
.if ${WITH_SETUID} == yes
CONFIGURE_ENV=        with_setuid=yes
.else
CONFIGURE_ENV=		with_setuid=no
.endif
.include <bsd.port.mk>
