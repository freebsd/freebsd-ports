# New ports collection makefile for:	tcsh with color-ls and kanji patches
# Version required:	6.07.06
# Date created:		29 November 1997
# Whom:			issei <issei@t-cnet.or.jp>
#
# $Id: Makefile,v 1.3 1997/12/28 22:11:37 asami Exp $
#

DISTNAME=	tcsh-6.07.06
PKGNAME=	ja-tcsh-6.07.06b4
CATEGORIES=	japanese shells
MASTER_SITES=	ftp://ftp.gw.com/pub/unix/tcsh/ \
		ftp://ftp.kobe-u.ac.jp/pub/shell/tcsh/ \
		ftp://ftp.netlab.is.tsukuba.ac.jp/pub/unix/shells/tcsh/ \
		http://www.is.s.u-tokyo.ac.jp/~nayuta/pub/ \
		ftp://ftp.lab.kdd.co.jp/Usenet/fj.sources/1998/jun/
DISTFILES=	${DISTNAME}.tgz ${DISTNAME}-color-1.07.tgz

PATCH_SITES=	http://www2.wbs.ne.jp/~znc/tcsh/ \
		ftp://ftp.lab.kdd.co.jp/Usenet/fj.sources/1998/jun/
PATCHFILES=	${DISTNAME}.kanji.patch7b4.gz
PATCH_DIST_STRIP=       -p1

MAINTAINER=	issei@t-cnet.or.jp

BUILD_DEPENDS=	nkf:${PORTSDIR}/japanese/nkf

GNU_CONFIGURE=	yes
ALL_TARGET=	all catalogs
INSTALL_TARGET=	install install.man
MAN1= 		tcsh.1
NLSDIR=		${PREFIX}/share/nls
PORTDOCS=	complete.tcsh FAQ HISTORY.kanji.patch.euc HowToMakeNLS.euc \
		README-color.ja README.kanji.patch.euc
ALL_CATALOGS=	ja ja.roomi ja.koshiki
USE_CATALOG?=	ja

post-patch:
	@-(cd ${WRKSRC}; \
	${PATCH} ${PATCH_DIST_ARGS} < ../color.patch ; \
	${PATCH} ${PATCH_DIST_ARGS} < ../kanji.patch ; \
	) > /dev/null 2>&1
.for i in ${ALL_CATALOGS}
	@(cd ${WRKSRC}/nls/$i; \
	${MKDIR} ../$i_s; \
	for j in * ; do \
	nkf -Es $$j | \
	${AWK} '{gsub(/[\x81-\x84\x88-\x9f\xe0-\xea]\\/,"&\\"); print; }' \
	> ../$i_s/$$j ; done ; \
	)
.endfor

post-install:
	@(cd ${WRKSRC}; \
	${INSTALL_DATA} tcsh.C.cat ${NLSDIR}/C/tcsh.cat; \
	${INSTALL_DATA} tcsh.C.m ${NLSDIR}/C/tcsh.m; \
	${INSTALL_DATA} tcsh.${USE_CATALOG}.cat ${NLSDIR}/ja_JP.EUC/tcsh.cat; \
	${INSTALL_DATA} tcsh.${USE_CATALOG}.m ${NLSDIR}/ja_JP.EUC/tcsh.m; \
	${INSTALL_DATA} tcsh.${USE_CATALOG}_s.cat ${NLSDIR}/ja_JP.SJIS/tcsh.cat; \
	${INSTALL_DATA} tcsh.${USE_CATALOG}_s.m ${NLSDIR}/ja_JP.SJIS/tcsh.m; \
	)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/tcsh
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/doc/tcsh/
.endfor
.endif
	@${ECHO} "updating /etc/shells"
	@${CP} /etc/shells /etc/shells.bak
	@(grep -v ${PREFIX}/bin/tcsh /etc/shells.bak; ${ECHO} ${PREFIX}/bin/tcsh) >/etc/shells

.include <bsd.port.mk>
