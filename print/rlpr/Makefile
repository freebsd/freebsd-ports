# New ports collection makefile for:	rlpr
# Date created:		11 April 1999
# Whom:			Mikhail Teterin
#
# $FreeBSD$
#

PORTNAME=	rlpr
PORTVERSION=	2.02
CATEGORIES=	print net
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/printing

MAINTAINER=	mi@aldan.algebra.com

#LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes
#CONFIGURE_ENV=	CPPFLAGS="-I${PREFIX}/include" LDFLAGS="-L${PREFIX}/lib -lintl"
CONFIGURE_ARGS=	--disable-nls --without-catgets

post-patch:
	# Replacing references to /etc/rlprrc to ${PREFIX}/etc/rlprrc
	@for f in ${WRKSRC}/src/rlprrc.h \
			`${GREP} -l /etc/rlprrc ${WRKSRC}/man/*.[0-9n]`; do \
		if test -e $$f.orig; then continue; fi; \
		${MV} $$f $$f.orig ; \
		${SED} s%/etc/rlprrc%${PREFIX}/etc/rlprrc%g < $$f.orig > \
			$$f ; \
	done

post-install:
	# Making the installed binaries suid,\
		      for the remote lpds to talk to them"
	${CHMOD} 4511 ${PREFIX}/bin/rlpq ${PREFIX}/bin/rlpr ${PREFIX}/bin/rlprm

MAN1=	rlpr.1 rlpq.1 rlprm.1
MAN5=	rlprrc.5
MAN8=	rlprd.8

.include <bsd.port.mk>
