# New ports collection makefile for:	cvsweb-converters
# Date created:		4 Mar 2001
# Whom:			Martin Kammerhofer <mkamm@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	cvsweb-converters
PORTVERSION=	0.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.sbox.TUGraz.at/home/d/dada/distfiles/

MAINTAINER=	mkamm@gmx.net

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/URI/Escape.pm:${PORTSDIR}/net/p5-URI \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Config/IniFiles.pm:${PORTSDIR}/devel/p5-Config-IniFiles \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Time/ParseDate.pm:${PORTSDIR}/devel/p5-Time

NO_BUILD=	yes
USE_PERL5=	yes

post-patch:
	@${PERL} -i -wpe '			\
	    s[ \@PREFIX\@ ](${PREFIX})gx;	\
	    s[ \@PERL5\@  ](${PERL})gx;		\
	' -- "${WRKSRC}"/*.pl.in

do-install:
	cd ${WRKSRC} &&						\
	${MKDIR} -- "${PREFIX}/bin" "${PREFIX}/etc" &&		\
	for f in cvsuplog2cvsweb.pl.in cvsrdiff2cvsweb.pl.in	\
	  commitlog2cvsweb.pl.in; do ${INSTALL_SCRIPT} --	\
		$$f "${PREFIX}/bin/`basename $$f .pl.in`";	\
	done &&							\
	${INSTALL_DATA} -- cvsweb-converters.conf.sample "${PREFIX}/etc"

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
