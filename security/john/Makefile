# ex:ts=8
# Ports collection makefile for:  ufcjohn
# Version required:     	  1.4
# Date created:			  Sun Mar 09, 1997
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $Id: Makefile,v 1.3 1997/03/10 17:39:35 obrien Exp $
#

DISTNAME=	ucfjohn3
PKGNAME=	john-1.4.2
CATEGORIES=	security
MASTER_SITES=	http://www.false.com/security/john/
EXTRACT_SUFX=	.zip

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	patch142.diff

MAINTAINER=     obrien@NUXI.com

BUILD_DEPENDS=  unzip:${PORTSDIR}/archivers/unzip

RESTRICTED=	"contains crypto (crypt())"

EXTRACT_CMD=    unzip
EXTRACT_ARGS=   -oqL
NO_WRKSUBDIR=   yes
ALL_TARGET=	freebsd

.if exists(/bin/tar)
TAR_CMD?=	/bin/tar
.else
TAR_CMD?=	/usr/bin/tar
.endif

post-extract:
	@(cd ${WRKSRC} ; ${TAR_CMD} -xzf sources.tgz)
	@(cd ${WRKSRC} ; ${EXTRACT_CMD} ${EXTRACT_ARGS} common.zip)
	@(cd ${WRKSRC} ; ${EXTRACT_CMD} ${EXTRACT_ARGS} doc.zip)

do-configure:
	/bin/mv ${WRKSRC}/john.ini ${WRKSRC}/john.ini.in
	sed -e "s:all.chr:${PREFIX}/share/john/all.chr:" \
	    -e "s:alpha.chr:${PREFIX}/share/john/alpha.chr:" \
	    -e "s:digits.chr:${PREFIX}/share/john/digits.chr:" \
	    ${WRKSRC}/john.ini.in > ${WRKSRC}/john.ini

do-install:
	@${MKDIR} ${PREFIX}/share/john
	@${INSTALL_PROGRAM} ${WRKSRC}/john ${PREFIX}/bin
	@(cd ${PREFIX}/bin ; /bin/ln -sf john xtract)
	@(cd ${PREFIX}/bin ; /bin/ln -sf john unshadow)
	@${INSTALL_DATA} ${WRKSRC}/all.chr ${PREFIX}/share/john
	@${INSTALL_DATA} ${WRKSRC}/alpha.chr ${PREFIX}/share/john
	@${INSTALL_DATA} ${WRKSRC}/digits.chr ${PREFIX}/share/john
	@${INSTALL_DATA} ${WRKSRC}/john.ini ${PREFIX}/share/john
	@${INSTALL_DATA} ${WRKSRC}/password.lst ${PREFIX}/share/john
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/john
	@${INSTALL_DATA} ${WRKSRC}/john.doc ${PREFIX}/share/doc/john
.endif

.include <bsd.port.mk>
