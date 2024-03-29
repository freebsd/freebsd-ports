PORTNAME=	portsnap
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	ports-mgmt net
MASTER_SITES=	http://www.daemonology.net/portsnap/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Provides secure snapshots of the ports directory
WWW=		http://www.daemonology.net/portsnap/

LICENSE=	BSD2CLAUSE

DEPRECATED=	portsnap infrastructure will be removed after the EOL of 13.x
EXPIRATION_DATE=2026-01-31

SUB_FILES=		pkg-message

PLIST_FILES=	"@sample etc/portsnap.conf.sample" \
				libexec/make_index \
				sbin/portsnap \
				share/man/man5/portsnap.conf.5.gz \
				share/man/man8/portsnap.8.gz

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1400087
IGNORE=	portsnap is in base systems and has been removed from 14.0-RELEASE
.endif

post-patch:
	${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" \
		${WRKSRC}/portsnap \
		${WRKSRC}/portsnap.conf.5 \
		${WRKSRC}/portsnap.8

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/portsnap ${STAGEDIR}/${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/make_index ${STAGEDIR}/${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/portsnap.conf.5 ${STAGEDIR}/${PREFIX}/share/man/man5/
	${INSTALL_MAN} ${WRKSRC}/portsnap.8 ${STAGEDIR}/${PREFIX}/share/man/man8/
	${INSTALL_DATA} ${WRKSRC}/portsnap.conf		\
		${STAGEDIR}/${PREFIX}/etc/portsnap.conf.sample

.include <bsd.port.post.mk>
