# New ports collection makefile for:	LPRng
# Version required:	3.2.3
# Date created:		2 Apr 1997
# Whom:			desmo@bandwidth.org
#
# $Id$
#

DISTNAME=	LPRng-3.2.3
CATEGORIES=	sysutils print
MASTER_SITES=	ftp://dickory.sdsu.edu/pub/LPRng/
EXTRACT_SUFX=	.tgz

MAINTAINER=	desmo@bandwidth.org

MAKEFILE=	Makefile.bsd
GNU_CONFIGURE=	yes

post-patch:
	@mv ${WRKSRC}/src/common/default.c ${WRKSRC}/src/common/default.c.tmp
	@${SED} -e "s|@@PREFIX@@|${PREFIX}|g" \
	    <${WRKSRC}/src/common/default.c.tmp >${WRKSRC}/src/common/default.c

pre-build:
	(cd ${WRKSRC}/po ; ln -s Makefile ${MAKEFILE})

post-install:
	(cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} default)
	${LDCONFIG} -m ${PREFIX}/lib
	${INSTALL} -d -g bin -o bin -m 0555 ${PREFIX}/share/doc/LPRng
	(cd ${WRKSRC} ; ${INSTALL_DATA} \
		README \
		README.1st \
		README.LPRng_to_lpr_spooling \
		README.accounting \
		README.authentication \
		README.banner \
		README.bouncequeues \
		README.deskjet \
		README.install \
		README.kerberos_authentication \
		README.logger \
		README.lp_Malformed_from_address \
		README.lp_emulation \
		README.lpd.conf \
		README.lpd.perms \
		README.nis \
		README.pgp_authentication \
		README.ports \
		README.printcap \
		README.routing \
		README.solaris \
		README.solaris.newsprint \
		README.statusdisplays \
		${PREFIX}/share/doc/LPRng )
	@cat ${FILESDIR}/lprng.sh | \
		${SED} -e "s|@@PREFIX@@|${PREFIX}|g" > ${PREFIX}/etc/rc.d/lprng.sh
	@chmod +x ${PREFIX}/etc/rc.d/lprng.sh
	@cat ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
