# New ports collection makefile for:	acroread
# Date created:		16 November 1996
# Whom:			Thomas Gellekum <tg@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	acroread5
PORTVERSION=	5.05
CATEGORIES=	print linux
MASTER_SITES=	ftp://ftp.adobe.com/pub/adobe/acrobatreader/unix/5.x/
.include <bsd.port.pre.mk>
.if ${ARCH} == "i386"
DISTNAME=	linux-505
.endif
MAINTAINER=	osa@FreeBSD.org.ru

RUN_DEPENDS=	/compat/linux/usr/i486-linux-libc5/lib/libc.so.5:${PORTSDIR}/emulators/linux_base

ONLY_FOR_ARCHS=	i386

NO_FILTER_SHLIBS=	yes

.if ${ARCH} == "i386"
PLIST_SUB=      "ARCHDIR=intellinux"
.endif
WRKSRC=		${WRKDIR}

pre-configure:
	@${PERL} -pi.fbsd -e 's:Linux\):FreeBSD|Linux):g' ${WRKDIR}/INSTALL

do-build:
	@${ECHO_MSG} "Do a \`make install' as root."

do-install:
	@${MKDIR} ${PREFIX}/Acrobat5
	@ReadInstallDir=${PREFIX}/Acrobat5 ${WRKDIR}/INSTALL

post-install:
	@${PERL} -pi -e 's:Linux\):FreeBSD|Linux):g' ${PREFIX}/Acrobat5/bin/acroread
	@/compat/linux/usr/bin/strip ${PREFIX}/Acrobat5/Reader/intellinux/bin/acroread
	@brandelf -t Linux ${PREFIX}/Acrobat5/Reader/intellinux/bin/acroread
	@${PERL} -pi -e 's:OSF1\):FreeBSD|OSF1):g' ${PREFIX}/Acrobat5/bin/acroread
	@cd ${PREFIX}/Acrobat5/bin && \
	  ${INSTALL_SCRIPT} ${PREFIX}/Acrobat5/bin/acroread \
	     ${PREFIX}/bin/acroread5
	@${CHOWN} -R -h root:wheel ${PREFIX}/Acrobat5
	@${CHMOD} +x ${PREFIX}/bin/acroread5
	@${ECHO_MSG} "Be sure to read the license agreement in"
	@${ECHO_MSG} "${PREFIX}/Acrobat5/Reader/license.txt"

.include <bsd.port.post.mk>
