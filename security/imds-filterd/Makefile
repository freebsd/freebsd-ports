# $FreeBSD$

PORTNAME=	imds-filterd
DISTVERSION=	0.1
CATEGORIES=	security

MAINTAINER=	cperciva@FreeBSD.org
COMMENT=	Provides per user/group access controls to the EC2 IMDS

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USE_GITHUB=	YES
GH_ACCOUNT=	cperciva

# Install binaries into ${STAGEDIR}${PREFIX}/sbin
MAKE_ARGS+=	BINDIR=${STAGEDIR}${PREFIX}/sbin

PORTDOCS=	README.md USAGE
PLIST_FILES=	etc/rc.d/imds-filterd		\
		etc/rc.d/imds-proxy		\
		sbin/imds-filterd		\
		sbin/imds-proxy			\
		"@sample etc/newsyslog.conf.d/imds.conf.sample"	\
		"@sample etc/syslog.d/imds.conf.sample"		\
		"@sample etc/imds.conf.sample"

OPTIONS_DEFINE=	DOCS

USERS=		imds
GROUPS=		imds

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/syslog.d
	${INSTALL_DATA} ${WRKSRC}/freebsd-conf/syslog-imds.conf ${STAGEDIR}${PREFIX}/etc/syslog.d/imds.conf.sample
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	${INSTALL_DATA} ${WRKSRC}/freebsd-conf/newsyslog-imds.conf ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/imds.conf.sample
	${INSTALL_DATA} ${WRKSRC}/imds.conf ${STAGEDIR}${PREFIX}/etc/imds.conf.sample
	${INSTALL_SCRIPT} ${WRKSRC}/freebsd-conf/rc.d-imds-filterd ${STAGEDIR}${PREFIX}/etc/rc.d/imds-filterd
	${INSTALL_SCRIPT} ${WRKSRC}/freebsd-conf/rc.d-imds-proxy ${STAGEDIR}${PREFIX}/etc/rc.d/imds-proxy

.include <bsd.port.mk>
