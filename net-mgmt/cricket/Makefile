# Created by: torstenb
# $FreeBSD$

PORTNAME=	cricket
PORTVERSION=	1.0.5
PORTREVISION=	9
CATEGORIES=	net-mgmt
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High performance, flexible monitoring system

RUN_DEPENDS=	rrdtool>=0:${PORTSDIR}/databases/rrdtool \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-SNMP_Session>=0:${PORTSDIR}/net-mgmt/p5-SNMP_Session \
		p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate

USES=		perl5
HAS_CONFIGURE=	yes
NO_BUILD=	yes
PLIST_SUB+=	VERSION=${PORTVERSION}
SUB_FILES=	pkg-message

# UID and username comes from ports/UIDs.
USERS=	cricket
GROUPS=	www

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,/home/cricket,${PREFIX},g' \
		${WRKSRC}/cricket-conf.pl.sample
	@${REINPLACE_CMD} -e 's,/usr/local/net/bin/ssh,/usr/bin/ssh,g' \
		${WRKSRC}/sample-config/news-server/Defaults

do-install:
	@${MKDIR} -m 755 ${PREFIX}/cricket/cricket-${PORTVERSION}
	@${CP} -R ${WRKSRC}/* ${PREFIX}/cricket/cricket-${PORTVERSION}
	@${FIND} ${PREFIX}/cricket/cricket-${PORTVERSION} -name \*.orig -or \
		-name \*.bak | ${XARGS} ${RM} -f
	${CHOWN} -R ${USERS}:${GROUPS} ${PREFIX}/cricket
	@if [ -L ${PREFIX}/cricket/cricket ]; then \
		${ECHO_MSG} "Updating ${PREFIX}/cricket/cricket symbolic link"; \
		${RM} ${PREFIX}/cricket/cricket; \
	fi
	${LN} -s ${PREFIX}/cricket/cricket-${PORTVERSION} \
		${PREFIX}/cricket/cricket
	@if [ -f ${LOCALBASE}/cricket/compile ] ; then \
		${ECHO_MSG} "You should migrate manually to use new cricket"; \
		${ECHO_MSG} "installation scheme."; \
	fi
	@${INSTALL_DATA} ${WRKSRC}/cricket-conf.pl.sample ${PREFIX}/etc/cricket-conf.pl.dist

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
