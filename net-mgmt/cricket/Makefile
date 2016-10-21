# Created by: torstenb
# $FreeBSD$

PORTNAME=	cricket
PORTVERSION=	1.0.5
PORTREVISION=	12
CATEGORIES=	net-mgmt
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High performance, flexible monitoring system

RUN_DEPENDS=	rrdtool>=0:databases/rrdtool \
		p5-libwww>=0:www/p5-libwww \
		p5-SNMP_Session>=0:net-mgmt/p5-SNMP_Session \
		p5-TimeDate>=0:devel/p5-TimeDate

USES=		perl5 shebangfix
SHEBANG_FILES=	util/metaQuery.pl
HAS_CONFIGURE=	yes
NO_BUILD=	yes
PLIST_SUB+=	VERSION=${PORTVERSION}
SUB_FILES=	pkg-message

# UID and username comes from ports/UIDs.
USERS=		cricket
GROUPS=		www

CRICKETBASE=	${STAGEDIR}${PREFIX}/cricket

post-patch:
	${REINPLACE_CMD} -e 's,/home/cricket,${PREFIX},g' \
		${WRKSRC}/cricket-conf.pl.sample
	${REINPLACE_CMD} -e 's,/usr/local/net/bin/ssh,/usr/bin/ssh,g' \
		${WRKSRC}/sample-config/news-server/Defaults

do-install:
	${MKDIR} -m 755 ${CRICKETBASE}/cricket-${PORTVERSION}
	${CP} -R ${WRKSRC}/* ${CRICKETBASE}/cricket-${PORTVERSION}
	${FIND} ${CRICKETBASE}/cricket-${PORTVERSION} -name \*.orig -or \
		-name \*.bak | ${XARGS} ${RM}
	${LN} -s cricket-${PORTVERSION} \
		${CRICKETBASE}/cricket
	if [ -f ${LOCALBASE}/cricket/compile ] ; then \
		${ECHO_MSG} "You should migrate manually to use new cricket"; \
		${ECHO_MSG} "installation scheme."; \
	fi
	${INSTALL_DATA} ${WRKSRC}/cricket-conf.pl.sample \
		${STAGEDIR}${PREFIX}/etc/cricket-conf.pl.dist

.include <bsd.port.mk>
