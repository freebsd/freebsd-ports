# New ports collection makefile for:	acroread
# Version required:	3.02
# Date created:		16 November 1996
# Whom:			Thomas Gellekum <tg@freebsd.org>
#
# $FreeBSD$
#

DISTNAME=	ar302lin
PKGNAME=	acroread-3.02
CATEGORIES=	print linux
MASTER_SITES=	ftp://ftp.adobe.com/pub/adobe/acrobatreader/unix/3.x/ \
		ftp://sunsite.cnlab-switch.ch/mirror/acrobatreader/unix/3.x/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tg@FreeBSD.org

RUN_DEPENDS=	/compat/linux/usr/i486-linux-libc5/lib/libc.so.5:${PORTSDIR}/emulators/linux_base

ONLY_FOR_ARCHS=	i386

NO_FILTER_SHLIBS=	yes

WRKSRC=		${WRKDIR}/ILINXR.install

do-build:
	@${ECHO_MSG} "Do a \`make install' as root."

do-install:
	@${MKDIR} ${PREFIX}/Acrobat3
	@ReadInstallDir=${PREFIX}/Acrobat3 ${WRKSRC}/INSTALL

post-install:
	@cd ${PREFIX}/Acrobat3/bin && \
	  ${PATCH} --quiet < ${FILESDIR}/acroread.diff && \
	  ${INSTALL_SCRIPT} ${PREFIX}/Acrobat3/bin/acroread ${PREFIX}/bin && \
	  ${RM} acroread.orig
	@brandelf -t Linux ${PREFIX}/Acrobat3/Reader/intellinux/bin/acroread
	@${CHMOD} +x ${PREFIX}/bin/acroread
	@${ECHO_MSG} "Be sure to read the license agreement in"
	@${ECHO_MSG} "${PREFIX}/Acrobat3/Reader/License.pdf"

.include <bsd.port.mk>
