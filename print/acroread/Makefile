# New ports collection makefile for:	acroread
# Date created:		16 November 1996
# Whom:			Thomas Gellekum <tg@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	acroread
PORTVERSION=	3.02
CATEGORIES=	print linux
MASTER_SITES=	ftp://ftp.adobe.com/pub/adobe/acrobatreader/unix/3.x/ \
		ftp://sunsite.cnlab-switch.ch/mirror/acrobatreader/unix/3.x/
.include <bsd.port.pre.mk>
.if ${ARCH} == "i386"
DISTNAME=	ar302lin
.elif ${ARCH} == "alpha"
DISTNAME=	ar302osf
.endif
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tg@FreeBSD.org

.if ${ARCH} == "i386"
RUN_DEPENDS=	/compat/linux/usr/i486-linux-libc5/lib/libc.so.5:${PORTSDIR}/emulators/linux_base
.elif ${ARCH} == "alpha"
RUN_DEPENDS=	/compat/osf1/usr/shlib/libc.so:${PORTSDIR}/emulators/osf1_base
.endif

ONLY_FOR_ARCHS=	i386 alpha

NO_FILTER_SHLIBS=	yes

.if ${ARCH} == "i386"
WRKSRC=		${WRKDIR}/ILINXR.install
PLIST_SUB=	"ARCHDIR=intellinux"
.elif ${ARCH} == "alpha"
WRKSRC=		${WRKDIR}/AOSFR.install
PLIST_SUB=	"ARCHDIR=alphaosf"
.endif

pre-configure:
.if ${ARCH} == "i386"
	@${PERL} -pi.fbsd -e 's:Linux\):FreeBSD|Linux):g' ${WRKSRC}/INSTALL
.elif ${ARCH} == "alpha"
	@${PERL} -pi.fbsd -e 's:OSF1\):FreeBSD|OSF1):g' ${WRKSRC}/INSTALL
.endif

do-build:
	@${ECHO_MSG} "Do a \`make install' as root."

do-install:
	@${MKDIR} ${PREFIX}/Acrobat3
	@ReadInstallDir=${PREFIX}/Acrobat3 ${WRKSRC}/INSTALL

post-install:
.if ${ARCH} == "i386"
	@${PERL} -pi -e 's:Linux\):FreeBSD|Linux):g' ${PREFIX}/Acrobat3/bin/acroread
	@brandelf -t Linux ${PREFIX}/Acrobat3/Reader/intellinux/bin/acroread
.elif ${ARCH} == "alpha"
	@${PERL} -pi -e 's:OSF1\):FreeBSD|OSF1):g' ${PREFIX}/Acrobat3/bin/acroread
.endif
	@cd ${PREFIX}/Acrobat3/bin && \
	  ${PATCH} --quiet < ${FILESDIR}/acroread.diff && \
	  ${INSTALL_SCRIPT} ${PREFIX}/Acrobat3/bin/acroread ${PREFIX}/bin && \
	  ${RM} acroread.orig
	@${CHMOD} +x ${PREFIX}/bin/acroread
	@${ECHO_MSG} "Be sure to read the license agreement in"
	@${ECHO_MSG} "${PREFIX}/Acrobat3/Reader/License.pdf"

.include <bsd.port.post.mk>
