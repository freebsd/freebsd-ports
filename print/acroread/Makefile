# New ports collection makefile for:	acroread
# Version required:	3.0
# Date created:		16 November 1996
# Whom:			Thomas Gellekum <tg@freebsd.org>
#
# $Id: Makefile,v 1.1.1.1 1996/11/20 07:29:45 tg Exp $
#

DISTNAME=	acroread_linux_b1106
PKGNAME=	acroread-3.0
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.adobe.com/pub/adobe/acrobatreader/unix/3.x/ \
		ftp://nic.switch.ch/mirror/Acrobat/unix/3.x/

MAINTAINER=	tg@FreeBSD.ORG

RUN_DEPENDS=	/compat/linux/lib/libc.so.5:${PORTSDIR}/emulators/linux_lib

NO_WRKSUBDIR=	yes

do-build:
	@${ECHO_MSG} "Do a \`make install' as root."

do-install:
	@mkdir -p ${PREFIX}/Acrobat3
	@mkdir -p ${PREFIX}/bin
	@ReadInstallDir=${PREFIX}/Acrobat3 ${WRKDIR}/INSTALL

post-install:
	@sed -e 's/Linux)/FreeBSD\|Linux)/' <${PREFIX}/Acrobat3/bin/acroread >${PREFIX}/bin/acroread
	@chmod +x ${PREFIX}/bin/acroread
	@${ECHO_MSG} "Be sure to read the license agreement in"
	@${ECHO_MSG} "${PREFIX}/Acrobat3/Reader/License.pdf"

.include <bsd.port.mk>
