# New ports collection makefile for:    texinfo
# Version required:     2.218
# Date created:         2 October 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.12 1997/05/21 13:31:21 jmz Exp $
#

DISTNAME=	texinfo
PKGNAME=	texinfo-2.218
DISTFILES=	texinfo.tex lcircle10.tfm
CATEGORIES=	print
#other equivalent sites: ftp.shsu.edu ftp.dante.de
MASTER_SITES=	ftp://ftp.tex.ac.uk/tex-archive/macros/eplain/doc/ \
		ftp://ftp.tex.ac.uk/tex-archive/fonts/latex/tfm/

MAINTAINER=     jmz@FreeBSD.org

BUILD_DEPENDS=	tex:${PORTSDIR}/print/tex
RUN_DEPENDS=	tex:${PORTSDIR}/print/tex

EXTRACT_ONLY=
NO_WRKSUBDIR=	yes

pre-configure:
	@${CP} ${DISTDIR}/texinfo.tex ${DISTDIR}/lcircle10.tfm ${WRKDIR}
	@chmod +w ${WRKDIR}/*

do-build: 
	@(cd ${WRKDIR}; initex '&tex texinfo @dump')

do-install: 
	@${INSTALL_DATA} ${WRKDIR}/texinfo.fmt \
				${PREFIX}/share/texmf/web2c/
	@if [ ! -f ${PREFIX}/share/texmf/fonts/tfm/lcircle10.tfm ]; then \
	  ${INSTALL_DATA} ${WRKDIR}/lcircle10.tfm \
				${PREFIX}/share/texmf/fonts/tfm/;\
	 fi
	@(cd ${PREFIX}/bin/; rm -f texinfo; ln -s virtex texinfo)

.include <bsd.port.mk>
