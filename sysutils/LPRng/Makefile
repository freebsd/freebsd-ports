# New ports collection makefile for:	LPRng
# Version required:	3.5.1
# Date created:		2 Apr 1997
# Whom:			desmo@bandwidth.org
#
# $FreeBSD$
#

DISTNAME=	LPRng-3.5.1
CATEGORIES=	sysutils print
MASTER_SITES=	ftp://ftp.astart.com/pub/LPRng/LPRng/
EXTRACT_SUFX=	.tgz
EXTRA_FILES=	LPRng_DOC-3.5.1.tgz
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${EXTRA_FILES}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	desmo@bandwidth.org

MAKEFILE=	Makefile.bsd
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lpddir=/usr/local/sbin

MAN1=		authenticate_pgp.1 cancel.1 lp.1 lpbanner.1 lpc.1 lpf.1 \
		lpq.1 lpr.1 lpraccnt.1 lprm.1 lpstat.1 monitor.1 \
		readfilecount.1
MAN5=		lpd.conf.5 lpd.perms.5 printcap.5
MAN8=		checkpc.8 lpd.8
MANCOMPRESSED=	yes

post-install:
	(cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} default)
	@${CAT} ${FILESDIR}/lprng.sh | \
		${SED} -e "s|@@PREFIX@@|${PREFIX}|g" > ${PREFIX}/etc/rc.d/lprng.sh
	@${CHMOD} +x ${PREFIX}/etc/rc.d/lprng.sh
	${INSTALL} -d -g bin -o bin -m 0555 ${PREFIX}/share/doc/LPRng
	@for file in ${EXTRA_FILES}; do \
		${CP} ${DISTDIR}/$$file ${PREFIX}/share/doc/LPRng; \
		cd ${PREFIX}/share/doc/LPRng; \
		tar xvfz $$file; \
		${RM} ${PREFIX}/share/doc/LPRng/$$file; \
	done
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
