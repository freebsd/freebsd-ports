# New ports collection makefile for:	pnm2ppa
# Date created:		18 November 1998
# Whom:			smace@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	pnm2ppa
PORTVERSION=	1.12
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert PNM images to PPA for some HP printers

USE_GHOSTSCRIPT_RUN=	yes

RUN_DEPENDS=	enscript:${PORTSDIR}/print/enscript-letter

USE_GETOPT_LONG=	yes
USE_GMAKE=	yes
MAKE_ENV=	LDFLAGS="${LDFLAGS}"
CFLAGS+=	${CPPFLAGS}

MAN1=		pnm2ppa.1

pre-everything::
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO_MSG} ""
	@${ECHO_MSG} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO_MSG} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO_MSG} ""
.endif

post-patch:
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
.if !exists(${PREFIX}/etc/pnm2ppa.conf)
	${CP} ${PREFIX}/etc/pnm2ppa.conf.sample ${PREFIX}/etc/pnm2ppa.conf
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
