# New ports collection makefile for:    aspathtree
# Date created:         06.05.2002
# Whom: Janos Mohacsi <janos.mohacsi@bsd.hu>
#
# $FreeBSD$

PORTNAME=	aspathtree
PORTVERSION=	4.2
PORTREVISION=	1
CATEGORIES=	net-mgmt ipv6
MASTER_SITES=	#http://carmen.ipv6.cselt.it/ipv6/tools/ASpath-tree/index.html
DISTNAME=	ASpath-tree-v${PORTVERSION}

MAINTAINER=	Janos.Mohacsi@bsd.hu
COMMENT=	Checks IPv6 routes' stability and correctness on IPv6 internet

RUN_DEPENDS=	${SITE_PERL}/Net/Telnet.pm:${PORTSDIR}/net/p5-Net-Telnet \
		whois3:${PORTSDIR}/net/ripe-whois

WRKSRC=			${WRKDIR}/ASpath-tree-v${PORTVERSION}/
RESTRICTED=		"not redistributable, license agreement required"

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=		"You need to read the license and disclaimer on http://carmen.ipv6.tilab.com/cgi-bin/download.pl?pkg=ASpath-tree and download ${DISTFILES} into ${DISTDIR}"
.endif

NO_BUILD=	yes
USE_PERL5=	yes
USE_REINPLACE=	yes
SCRIPTS_ENV+=	PERL5=${PERL5}
PKGMESSAGE=	${WRKDIR}/pkg-message
CONFIG_FILES=	ASpath-tree.config
ICON_FILES=	bnew.gif bold.gif e.gif h.gif l.gif p.gif t.gif v.gif
LIB_FILES=	bgp-tree-changes.pl bgp-tree.pl create-homepage.pl elaborate-aspaths.pl getbgptable.pl history.pl ipv6prefix.pl odd-as.pl odd-routes.pl route-stability.pl utility.pl ASmain.pl
DATA_FILES=	6bone.db force.as.name rirs.db
DOC_FILES=	DISCLAIMER readme.txt changes.txt

pre-configure:
	@${REINPLACE_CMD} -e 's#%%PATHPERLBIN%%#${PERL5}#; \
		s#%%PREFIX%%#${PREFIX}#' ${WRKSRC}/update-rtree \
			${WRKSRC}/etc/ASpath-tree.config

do-install:
#installing main script
	${INSTALL_SCRIPT} ${WRKSRC}/update-rtree ${PREFIX}/bin
#installing lib files
	${MKDIR} ${PREFIX}/libexec/aspathtree/
.for file in ${LIB_FILES}
	${INSTALL_DATA} ${WRKSRC}/lib/${file} ${PREFIX}/libexec/aspathtree
.endfor
#installing htdocs files
	${MKDIR} ${PREFIX}/var/aspathtree/htdocs/icons/
.for file in ${ICON_FILES}
	${INSTALL_DATA} ${WRKSRC}/htdocs/icons/${file} ${PREFIX}/var/aspathtree/htdocs/icons/
.endfor
#installing data files
	${MKDIR} ${PREFIX}/var/aspathtree/data
.for file in ${DATA_FILES}
	${INSTALL_DATA} ${WRKSRC}/data/${file} ${PREFIX}/var/aspathtree/data/
.endfor
#installing log directory
	${MKDIR} ${PREFIX}/var/aspathtree/log
#installing config files
.for file in ${CONFIG_FILES}
	${INSTALL_DATA} ${WRKSRC}/etc/${file} ${PREFIX}/etc/${file}.dist
.endfor
#installing docs
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

post-install:
	@${SED} -e "s:%%PREFIX%%:${PREFIX}:g" ${.CURDIR}/pkg-message >${PKGMESSAGE}
.if !defined(BATCH)
	@${ECHO}
	@${CAT} ${PKGMESSAGE}
	@${ECHO}
.endif

.include <bsd.port.post.mk>
