# New ports collection makefile for:    texinfo
# Version required:     2.124
# Date created:         2 October 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.5 1995/04/17 20:31:38 asami Exp $
#

DISTNAME=	texinfo
PKGNAME=	texinfo-2.124
DISTFILES=	texinfo.tex lcircle10.tfm
CATEGORIES+=	printing
#other equivalent sites: ftp.shsu.edu ftp.dante.de
MASTER_SITES=	ftp://ftp.tex.ac.uk/tex-archive/macros/eplain/doc/ \
		ftp://ftp.tex.ac.uk/tex-archive/fonts/latex/tfm/

MAINTAINER=     jmz@FreeBSD.org

EXEC_DEPENDS=   tex:${PORTSDIR}/print/tex


EXTRACT_ONLY=
NO_WRKSUBDIR=	yes



pre-fetch:
	@if [ ! -x ${PREFIX}/bin/tex ]; then \
	  echo "You must have TeX installed";\
	  exit 1; \
	 fi;
	 @if [ ! -x ${PREFIX}/bin/initex ]; then \
	  echo "I can't find initex. Your TeX installation is incomplete";\
	  exit 1;\
	 fi

pre-configure:
	@cp ${DISTDIR}/texinfo.tex ${DISTDIR}/lcircle10.tfm ${WRKDIR}
	@chmod +w ${WRKDIR}/*

do-build: 
	@(cd ${WRKDIR}; initex '&tex texinfo @dump')

do-install: 
	@/usr/bin/install -c -m 644 ${WRKDIR}/texinfo.fmt \
				${PREFIX}/lib/texmf/ini/
	@if [ ! -f ${PREFIX}/lib/texmf/fonts/tfm/lcircle10.tfm ]; then \
	  /usr/bin/install -c -m 644 ${WRKDIR}/lcircle10.tfm \
				${PREFIX}/lib/texmf/fonts/tfm/;\
	 fi
	@(cd ${PREFIX}/bin/; rm -f texinfo; ln -s virtex texinfo)

.include <bsd.port.mk>
