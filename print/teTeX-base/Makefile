# New ports collection makefile for:	teTeX
# Version required:	0.4
# Date created:		5 December 1996
# Whom:			Bernd Rosauer <br@schiele-ct.de>
#
# $Id: Makefile,v 1.26 1998/11/28 09:07:14 asami Exp $
#

DISTNAME=	teTeX-src-0.4
PKGNAME=	teTeX-0.4
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	systems/unix/teTeX/distrib/sources
DISTFILES=	${TETEX_SRC} ${TETEX_LIB}

MAINTAINER=	br@netland.inka.de

USE_XLIB=	yes
USE_GMAKE=	yes
DIST_SUBDIR=	teTeX
PATCH_DIST_STRIP=	-p1
ALL_TARGET=	config clean texhash all
INSTALL_TARGET=	install ini
MAN1=		afm2tfm.1 allcm.1 alldc.1 allneeded.1 amslatex.1 \
		amstex.1 append_db.1 bibtex.1 dvilj.1 dvips.1 \
		dvired.1 dvitype.1 etex.1 fontexport.1 fontimport.1 \
		gftodvi.1 gftopk.1 gftype.1 gsftopk.1 initex.1 \
		lamstex.1 latex.1 mag.1 makeindex.1 mf.1 mft.1 \
		mp.1 patgen.1 pfb2pfa.1 pk2bm.1 pktogf.1 pktype.1 \
		pltotf.1 pooltype.1 ps2frag.1 ps2pk.1 slitex.1 \
		tangle.1 tex.1 texconfig.1 texhash.1 tftopl.1 \
		vftovp.1 virtex.1 vptovf.1 weave.1 xdvi.1

TETEX_SRC=	teTeX-src-0.4pl7.tar.gz
TETEX_LIB=	teTeX-lib-0.4pl8.tar.gz
WRKLIB=		${WRKDIR}/teTeX
INSTALL_INFO=	/usr/bin/install-info

pre-install:
	@if [ -x ${PREFIX}/bin/mp ]; then ${MV} ${PREFIX}/bin/mp ${PREFIX}/bin/mp.save; fi
	@${RM} -f ${PREFIX}/share/texmf/ls-R
	@chown -R bin:bin ${WRKLIB}/info ${WRKLIB}/man
	@${RM} -f ${WRKLIB}/info/dir ${WRKLIB}/info/localdir ${WRKLIB}/info/*.orig
	@chmod 444 ${WRKLIB}/info/* ${WRKLIB}/man/man1/* ${WRKLIB}/man/man5/*
	@find ${WRKLIB}/texmf/fonts -type d -perm 1755 -exec chmod 755 {} \;
	@ (cd ${WRKLIB}; tar cf - info man/man1 man/man5) | (cd ${PREFIX}; tar --unlink -xpf -)
	@ (cd ${WRKLIB}; tar cf - texmf) | (cd ${PREFIX}/share; tar --unlink -xpf -)
	@${INSTALL_DATA} ${WRKLIB}/texmf.cnf ${PREFIX}/share/texmf/web2c

post-install:
	${RM} ${PREFIX}/bin/install-info
	${INSTALL_INFO} ${PREFIX}/info/latex ${PREFIX}/info/dir
	${INSTALL_INFO} ${PREFIX}/info/kpathsea.info ${PREFIX}/info/dir
	${INSTALL_INFO} ${PREFIX}/info/dvips.info ${PREFIX}/info/dir
	${INSTALL_INFO} ${PREFIX}/info/fontname.info ${PREFIX}/info/dir
	@${MV} ${PREFIX}/bin/mp ${PREFIX}/bin/mpost
	@if [ -x ${PREFIX}/bin/mp.save ]; then ${MV} ${PREFIX}/bin/mp.save ${PREFIX}/bin/mp; fi
	@${SETENV} PREFIX=${PREFIX} ${SH} files/install-note

.include <bsd.port.mk>
