# New ports collection makefile for:	acroread
# Version required:	4.0
# Date created:		16 November 1996
# Whom:			Thomas Gellekum <tg@freebsd.org>
#
# $FreeBSD$
#

DISTNAME=	linux-ar-40
PKGNAME=	acroread-4.0
CATEGORIES=	print
MASTER_SITES=	ftp://ftp-pac.adobe.com/pub/adobe/acrobatreader/unix/4.x/

MAINTAINER=	dima@FreeBSD.org

RUN_DEPENDS=	/compat/linux/usr/i486-linux-libc5/lib/libc.so.5:${PORTSDIR}/emulators/linux_base

NO_LATEST_LINK=	yes

ONLY_FOR_ARCHS=	i386

NO_FILTER_SHLIBS=	yes

WRKSRC=		${WRKDIR}/ILINXR.install

do-build:
	@${ECHO_MSG} "Do a \`make install' as root."

do-install:
	@${MKDIR} ${PREFIX}/Acrobat4
	@ReadInstallDir=${PREFIX}/Acrobat4 ${WRKSRC}/INSTALL

post-install:
	@cd ${PREFIX}/Acrobat4/bin && \
	  ${PATCH} --quiet < ${FILESDIR}/acroread.diff && \
	  ${INSTALL_SCRIPT} ${PREFIX}/Acrobat4/bin/acroread \
	     ${PREFIX}/bin/acroread4 && ${RM} acroread.orig
	@strip ${PREFIX}/Acrobat4/Reader/intellinux/bin/acroread
	@brandelf -t Linux ${PREFIX}/Acrobat4/Reader/intellinux/bin/acroread
	@${CHMOD} +x ${PREFIX}/bin/acroread4
	@${ECHO_MSG} "Be sure to read the license agreement in"
	@${ECHO_MSG} "${PREFIX}/Acrobat4/Reader/License.pdf"

.include <bsd.port.mk>
