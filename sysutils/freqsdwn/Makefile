# Created by: n-shigemura@ensure.jp
# $FreeBSD$

PORTNAME=	freqsdwn
PORTVERSION=	2.00
CATEGORIES=	sysutils japanese
MASTER_SITES=	http://www.mitsubishielectric.co.jp/frequps/f_down/f_dl_sw_data/
DISTNAME=	${PORTNAME:C/freq//}_${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	freqship

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FREQSHIP-mini Mitsubishi Electric UPS controller daemon

RESTRICTED=	See http://www.mitsubishielectric.co.jp/frequps/f_down/keiyaku.html
.if defined(BATCH) || defined(PACKAGE_BUILDING)
IGNORE=		${RESTRICTED}
.endif

USE_RC_SUBR=	freqshpd 000.freqshpk
PLIST_SUB=	PORTNAME=${PORTNAME} CONFDIR=${CONFDIR}
SUB_LIST=	PORTNAME=${PORTNAME} CONFDIR=${CONFDIR}
OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/freqship
PORTDOCS=	README

CONFDIR?=	${PREFIX}/etc/freqship

NO_STAGE=	yes
pre-fetch::
	@[ -f ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} ] || (   \
	${ECHO} "Please read and accept following LICENSE:";                \
	${ECHO} "http://www.mitsubishielectric.co.jp/frequps/f_down/keiyaku.html"; \
	${ECHO} "Please 'make do-fetch' manually, if you accept it.";       \
	${FALSE})

post-extract:
	@${CP} ${WRKSRC}/common/freqship.org ${WRKSRC}/common/freqship.h
	@${CP} ${FILESDIR}/UPSFILE ${WRKSRC}/initdata/
.for dir in subdir daemon upsdown
	@${CP} ${FILESDIR}/Makefile.${dir} ${WRKSRC}/${dir:subdir=}/Makefile
.endfor

.include <bsd.port.options.mk>

post-install:
	@${MKDIR} ${CONFDIR}
.for FILE in UPSFILE UPSSTAT PMSGERR PMSGOK DELAY
	@${INSTALL_DATA} ${WRKSRC}/initdata/${FILE} ${PREFIX}/etc/freqship/${FILE}-dist
	@[ -f ${PREFIX}/etc/freqship/${FILE} ] || \
		${CP} ${WRKSRC}/initdata/${FILE} ${PREFIX}/etc/freqship/${FILE}
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
