# New ports collection makefile for:	siproxd
# Date created:		10 October 2004
# Whom:			Frank W. Josellis <frank@dynamical-systems.org>
#
# $FreeBSD$
#

PORTNAME=	siproxd
PORTVERSION=	0.5.8
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	siproxd

MAINTAINER=	frank@dynamical-systems.org
COMMENT=	A proxy/masquerading daemon for the SIP protocol

LIB_DEPENDS=	osip2.2:${PORTSDIR}/net/libosip2

USE_GETOPT_LONG=yes
USE_RC_SUBR=	yes
HAS_CONFIGURE=	yes

PORTDOCS=	AUTHORS ChangeLog README RELNOTES \
		doc/FAQ doc/KNOWN_BUGS doc/RFC3261_compliance.txt \
		doc/sample_cfg_budgetone.txt doc/sample_cfg_x-lite.txt

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500041
LIB_DEPENDS+=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%RC_SUBR%%|${RC_SUBR}|g' \
		${FILESDIR}/siproxd.sh > ${PREFIX}/etc/rc.d/siproxd.sh
	@${CHMOD} 755 ${PREFIX}/etc/rc.d/siproxd.sh

.include <bsd.port.post.mk>
