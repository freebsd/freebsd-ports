# New ports collection makefile for:	rlpr
# Version required:	2.0
# Date created:		11 April 1999
# Whom:			Mikhail Teterin
#
# $Id$

DISTNAME=	rlpr-2.00
CATEGORIES=	print net
MASTER_SITES=	ftp://sherilyn.ne.mediaone.net/pub/

MAINTAINER=	mi@aldan.algebra.com

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${PREFIX}/include" LDFLAGS="-L${PREFIX}/lib -lintl"
CONFIGURE_ARGS=	--with-catgets

RLPRRC=	${WRKSRC}/src/rlprrc.h

post-patch:
	@echo "Replacing references to /etc/rlprrc to ${PREFIX}/etc/rlprrc"
	@test -e ${RLPRRC}.orig || ${MV} ${RLPRRC} ${RLPRRC}.orig && \
		${SED} s%/etc/%${PREFIX}/etc/% ${RLPRRC}.orig > ${RLPRRC}
	@for man in `${GREP} -l /etc/rlprrc ${WRKSRC}/man/*.[0-9n]`; do \
		if test -e $$man.orig; then continue; fi; \
		${MV} $$man $$man.orig ; \
		${SED} s%/etc/rlprrc%${PREFIX}/etc/rlprrc%g < $$man.orig > \
			$$man ; \
	done

post-install:
	@echo "Making the installed binaries suid,\
		for the remote lpds to talk to them"
	chmod u+s ${PREFIX}/bin/rlpq ${PREFIX}/bin/rlpr ${PREFIX}/bin/rlprm

MAN1=	rlpr.1 rlpq.1 rlprm.1
MAN5=	rlprrc.5
MAN8=	rlprd.8

.include <bsd.port.mk>
