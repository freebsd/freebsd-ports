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
COMMENT=	Create hyperlinks to cvsweb from cvs[up] output or FreeBSD commitlogs

RUN_DEPENDS=	${SITE_PERL}/URI/Escape.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/${PERL_ARCH}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib \
		${SITE_PERL}/Config/IniFiles.pm:${PORTSDIR}/devel/p5-Config-IniFiles \
		${SITE_PERL}/Time/ParseDate.pm:${PORTSDIR}/devel/p5-Time-modules

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
