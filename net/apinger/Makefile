# ex:ts=8
# Ports collection makefile for:  apinger
# Date created:                          Tue Jul 17, 2002
# Whom:                                  Michael L. Hostbaek (mich@freebsdcluster.org)
#
# $FreeBSD$
#

PORTNAME=	apinger
PORTVERSION=	0.6.1
PORTREVISION=	1
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.bnet.pl/~jajcus/apinger/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	An IP device monitoring tool

GNU_CONFIGURE=	yes

OPTIONS=	IPV6 "With support for IPv6" on

.include <bsd.port.pre.mk>

.if !defined(WITH_IPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

post-extract:
	@${SED} -e "s,%%PREFIX%%,${PREFIX},g" ${FILESDIR}/apinger.sh \
		> ${WRKSRC}/apinger.sh

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/apinger.conf ${PREFIX}/etc/apinger.conf.sample
	${INSTALL_SCRIPT} ${WRKSRC}/apinger.sh ${PREFIX}/etc/rc.d/apinger.sh.sample
.if !defined(BATCH)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "###############################################################################"
	@${ECHO_MSG} "# Please edit ${PREFIX}/etc/apinger.conf to your needs.                      #"
	@${ECHO_MSG} "# A sample shell script has been installed in ${PREFIX}/etc/rc.d/            #"
	@${ECHO_MSG} "# rename it to automatically start apinger at boot.                           #"
	@${ECHO_MSG} "###############################################################################"
.endif

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/NEWS ${DOCSDIR}/NEWS
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DOCSDIR}/AUTHORS
.endif

.include <bsd.port.post.mk>
