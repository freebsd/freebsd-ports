# New ports collection makefile for:	fcgi-devkit
# Version required:    2.1
# Date created:        13 May 1999
# Whom:                kbyanc
#
# $FreeBSD$
#

DISTNAME=	fcgi-devkit-2.1
CATEGORIES=	www
MASTER_SITES=	http://fastcgi.idle.com/dist/

MAINTAINER=	kbyanc@posi.net

MAN1=		cgi-fcgi.1
MAN3=		FCGI_Accept.3 FCGI_Finish.3 FCGI_SetExitStatus.3 FCGI_StartFilterData.3

USE_PERL5=	yes
GNU_CONFIGURE=	yes

post-install:
	@${RM} -f ${PREFIX}/fcgi-devkit/libfcgi/os_unix.c.orig \
	       ${PREFIX}/fcgi-devkit/Makefile.in.orig

.include <bsd.port.mk>
