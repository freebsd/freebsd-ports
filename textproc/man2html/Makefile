# New ports collection makefile for:   	man2html
# Version required:			3.0.1
# Date created:				29 August 1998
# Whom:                			Dima Sivachenko <demon@gpad.ac.ru>
#
# $Id: Makefile,v 1.1.1.1 1998/11/22 22:33:31 billf Exp $
#

DISTNAME=	man2html3.0.1
PKGNAME=	man2html-3.0.1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.gpad.ac.ru/pub/FreeBSD/distfiles/

MAINTAINER=	demon@gpad.ac.ru

USE_PERL5=	yes
NO_BUILD=	yes
CGIDIR=		${PREFIX}/www/cgi-bin

MAN1=  		man2html.1

post-patch:

	@ if [ -f ${CGIDIR} ] ; then \
		@ ${MV} ${WRKSRC}/man.cgi ${WRKSRC}/man.cgi.pre_sed ; \
		@ ${CAT} ${WRKSRC}/man.cgi.pre_sed | \
		@ ${GREP} -Ev -e "/opt/|/openwin/" \
		> ${WRKSRC}/man.cgi ; \
	fi

do-install:

	cd ${WRKSRC} && \
	${PERL5} ${WRKSRC}/install.me -batch -binpath ${PREFIX}/bin \
	-manpath ${PREFIX}/man -libpath ${PREFIX}/lib \
	-perlpath ${PERL5}
	if [ -f ${CGIDIR} ] ; then \
		${INSTALL_PROGRAM} ${WRKSRC}/man.cgi ${CGIDIR} ; \
	fi

.include <bsd.port.mk>
