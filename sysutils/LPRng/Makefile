# New ports collection makefile for:	LPRng
# Date created:		2 Apr 1997
# Whom:			desmo@bandwidth.org
#
# $FreeBSD$
#

PORTNAME=	LPRng
PORTVERSION=	3.6.8
CATEGORIES=	sysutils print
MASTER_SITES=	ftp://ftp.astart.com/pub/LPRng/LPRng/
EXTRACT_SUFX=	.tgz
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${LPRNG_DOC}

MAINTAINER=	desmo@bandwidth.org

PLIST_SUB+=	LPRNG_VER=${PORTVERSION}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
LPRNG_DOC=	LPRng_DOC-${PORTVERSION}.tgz

MAKEFILE=	Makefile.bsd
HAS_CONFIGURE=	yes
CONFIGURE_ARGS= \
		--with-sbindir=${PREFIX}/sbin \
		--with-filterdir=${PREFIX}/libexec/filters \
		--with-lpd_conf_path=/etc/lpd.conf \
		--with-lpd_perms_path=/etc/lpd.perms \
		--with-printcap_path=/etc/printcap

MAN1=		cancel.1 lp.1 lpbanner.1 lpc.1 lpf.1 \
		lpq.1 lpr.1 lpraccnt.1 lprm.1 lpstat.1 monitor.1
MAN5=		lpd.conf.5 lpd.perms.5 printcap.5
MAN8=		checkpc.8 lpd.8
MANCOMPRESSED=	yes

post-install:
	${CAT} ${FILESDIR}/lprng.sh | \
		${SED} -e "s|@@PREFIX@@|${PREFIX}|g" > ${PREFIX}/etc/rc.d/lprng.sh
	${CHMOD} +x ${PREFIX}/etc/rc.d/lprng.sh
	${INSTALL} -d -g bin -o bin -m 0555 ${PREFIX}/share/doc/LPRng
	cd ${PREFIX}/share/doc/LPRng; \
		tar xvfz ${DISTDIR}/${LPRNG_DOC}
	@${CAT} ${PKGDIR}/MESSAGE | \
		${SED} -e "s|@@PREFIX@@|${PREFIX}|g"

.include <bsd.port.mk>
