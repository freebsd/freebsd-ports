# New ports collection makefile for:	acroread
# Version required:	3.01
# Date created:		16 November 1996
# Whom:			Thomas Gellekum <tg@freebsd.org>
#
# $Id: Makefile,v 1.3 1997/02/17 09:07:27 tg Exp $
#

DISTNAME=	acroread_linux_301
PKGNAME=	acroread-3.01
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.adobe.com/pub/adobe/acrobatreader/unix/3.x/ \
		ftp://sunsite.cnlab-switch.ch/mirror/acrobatreader/unix/3.x/

MAINTAINER=	tg@FreeBSD.ORG

RUN_DEPENDS=	/compat/linux/lib/libc.so.5:${PORTSDIR}/emulators/linux_lib

NO_WRKSUBDIR=	yes

do-build:
	@${ECHO_MSG} "Do a \`make install' as root."

do-install:
	@${MKDIR} ${PREFIX}/Acrobat3
	@ReadInstallDir=${PREFIX}/Acrobat3 ${WRKDIR}/INSTALL

post-install:
	@sed -e 's/Linux)/FreeBSD\|Linux)/' <${PREFIX}/Acrobat3/bin/acroread >${PREFIX}/bin/acroread
	@chmod +x ${PREFIX}/bin/acroread
	@${ECHO_MSG} "Be sure to read the license agreement in"
	@${ECHO_MSG} "${PREFIX}/Acrobat3/Reader/License.pdf"

.include <bsd.port.mk>
