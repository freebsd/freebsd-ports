# New ports collection makefile for:	siproxd
# Date created:		10 October 2004
# Whom:			Frank W. Josellis <frank@dynamical-systems.org>
#
# $FreeBSD$
#

PORTNAME=	siproxd
PORTVERSION=	0.5.11
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	siproxd

MAINTAINER=	frank@dynamical-systems.org
COMMENT=	A proxy/masquerading daemon for the SIP protocol

LIB_DEPENDS=	osip2.3:${PORTSDIR}/net/libosip2

USE_REINPLACE=	yes
USE_GETOPT_LONG=yes
USE_RC_SUBR=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	# empty

PORTDOCS1=	AUTHORS ChangeLog README RELNOTES
PORTDOCS2=	FAQ KNOWN_BUGS RFC3261_compliance.txt \
		sample_cfg_budgetone.txt sample_cfg_x-lite.txt
PORTDOCS=	${PORTDOCS1} ${PORTDOCS2}
PLIST_FILES=	etc/rc.d/siproxd.sh etc/siproxd.conf.example \
		etc/siproxd_passwd.cfg sbin/siproxd

.include <bsd.port.pre.mk>

post-patch:
.if ${OSVERSION} >= 500041
	@${REINPLACE_CMD} -e 's,-lgnugetopt,,g' ${WRKSRC}/${CONFIGURE_SCRIPT}
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS1}
	${INSTALL_MAN} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.for i in ${PORTDOCS2}
	${INSTALL_MAN} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
.endif
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%RC_SUBR%%|${RC_SUBR}|g' \
		${FILESDIR}/siproxd.sh > ${PREFIX}/etc/rc.d/siproxd.sh
	@${CHMOD} 755 ${PREFIX}/etc/rc.d/siproxd.sh

.include <bsd.port.post.mk>
