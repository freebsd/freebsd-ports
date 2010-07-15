# New ports collection makefile for:	pnm2ppa
# Date created:		18 November 1998
# Whom:			smace@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	pnm2ppa
PORTVERSION=	1.13
CATEGORIES=	print
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert PNM images to PPA for some HP printers

OPTIONS=	A4SIZE "Set A4 (not Letter) as a default paper size" off

USE_GHOSTSCRIPT_RUN=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		pnm2ppa.1
PLIST_FILES=	bin/asciippafilter bin/calibrate_ppa bin/pnm2ppa bin/ppafilter \
		etc/pnm2ppa.conf.sample

PKGDEINSTALL=	${PKGINSTALL}

.include <bsd.port.pre.mk>

.if defined(A4) || defined(WITH_A4SIZE)
RUN_DEPENDS=	enscript:${PORTSDIR}/print/enscript-a4
.else
RUN_DEPENDS=	enscript:${PORTSDIR}/print/enscript-letter
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Wformat-security -g|-Wformat-security| ; \
		 s|-O2 -DNDEBUG|-DNDEBUG|' ${WRKSRC}/configure
	@${SED} -e "s:%%PREFIX%%:${PREFIX}:g" \
		${WRKSRC}/pnm2ppa.conf > ${WRKSRC}/pnm2ppa.conf.sample
	@${SED} -e "s:%%PREFIX%%:${PREFIX}:g" \
		${WRKSRC}/docs/en/pnm2ppa.1 > ${WRKSRC}/pnm2ppa.1
	@${SED} -e "s:%%PREFIX%%:${PREFIX}:g" \
	        -e "s:%%LOCALBASE%%:${LOCALBASE}:g" \
		${FILESDIR}/asciippafilter.SH > ${WRKSRC}/asciippafilter
	@${SED} -e "s:%%PREFIX%%:${PREFIX}:g" \
	        -e "s:%%LOCALBASE%%:${LOCALBASE}:g" \
		${FILESDIR}/ppafilter.SH > ${WRKSRC}/ppafilter

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/calibrate_ppa ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/pnm2ppa ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/asciippafilter ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ppafilter ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pnm2ppa.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/pnm2ppa.conf.sample ${PREFIX}/etc
	@${SETENV} PKG_PREFIX="${PREFIX}" \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
