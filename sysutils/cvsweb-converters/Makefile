# New ports collection makefile for:	cvsweb-converters
# Date created:		4 Mar 2001
# Whom:			Martin Kammerhofer <mkamm@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	cvsweb-converters
PORTVERSION=	0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.sbox.TUGraz.at/home/d/dada/distfiles/

MAINTAINER=	mkamm@gmx.net

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/URI/Escape.pm:${PORTSDIR}/net/p5-URI \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib

NO_BUILD=	yes
USE_PERL5=	yes

post-patch:
	@${PERL} -i -wpe '			\
	    s[ /usr/local ](${PREFIX})gx;	\
	    s[ !!PERL!!   ](${PERL})gx;		\
	' -- "${WRKSRC}"/*.pl

do-install:
	cd ${WRKSRC} &&							\
	${MKDIR} -- "${PREFIX}/bin" "${PREFIX}/etc" &&			\
	for f in *.pl; do						\
	  ${INSTALL_SCRIPT} -- $$f "${PREFIX}/bin/`basename $$f .pl`";	\
	done &&								\
	${INSTALL_DATA} -- commitlog2cvsweb.conf.sample "${PREFIX}/etc"

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
