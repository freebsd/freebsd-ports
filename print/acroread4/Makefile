# New ports collection makefile for:	acroread
# Version required:	3.02
# Date created:		16 November 1996
# Whom:			Thomas Gellekum <tg@freebsd.org>
#
# $Id: Makefile,v 1.6 1998/10/12 12:26:42 jseger Exp $
#

DISTNAME=	ar302lin
PKGNAME=	acroread-3.02
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.adobe.com/pub/adobe/acrobatreader/unix/3.x/ \
		ftp://sunsite.cnlab-switch.ch/mirror/acrobatreader/unix/3.x/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tg@FreeBSD.ORG

NO_FILTER_SHLIBS=	yes

RUN_DEPENDS=	/compat/linux/lib/libc.so.5:${PORTSDIR}/emulators/linux_lib

WRKSRC=		${WRKDIR}/ILINXR.install

do-build:
	@${ECHO_MSG} "Do a \`make install' as root."

do-install:
	@${MKDIR} ${PREFIX}/Acrobat3
	@ReadInstallDir=${PREFIX}/Acrobat3 ${WRKSRC}/INSTALL

post-install:
	@sed -e 's/Linux)/FreeBSD\|Linux)/' <${PREFIX}/Acrobat3/bin/acroread >${PREFIX}/bin/acroread
	@chmod +x ${PREFIX}/bin/acroread
	@${ECHO_MSG} "Be sure to read the license agreement in"
	@${ECHO_MSG} "${PREFIX}/Acrobat3/Reader/License.pdf"

.include <bsd.port.mk>
