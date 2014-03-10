# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	duo
PORTVERSION=	1.9.7
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	https://dl.duosecurity.com/ \
		http://mirrors.rit.edu/zi/
DISTNAME=	${PORTNAME}_unix-${PORTVERSION}

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Duo unix integration package

LICENSE=	GPLv2

CONFIGURE_ARGS=	--with-pam=${PREFIX}/lib/security --sysconfdir=${PREFIX}/etc \
		--docdir=${DOCSDIR} --includedir=${PREFIX}/include/${PORTNAME}

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${OSVERSION} >= 1000000
USE_GCC=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/login_duo/login_duo.8
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/pam_duo/pam_duo.8
.if !${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's|README AUTHORS CHANGES LICENSE||g' ${WRKSRC}/Makefile.in
.endif

post-install:
	@${INSTALL} -o sshd -g wheel -m 700 ${WRKSRC}/login_duo/login_duo.conf \
	    ${STAGEDIR}${PREFIX}/etc/login_duo.conf.sample
	@${INSTALL_DATA} -m 700 ${WRKSRC}/pam_duo/pam_duo.conf \
	    ${STAGEDIR}${PREFIX}/etc/pam_duo.conf.sample
	@if [ ! -f ${PREFIX}/etc/login_duo.conf ]; then \
		${CP} -p ${STAGEDIR}${PREFIX}/etc/login_duo.conf.sample \
		    ${STAGEDIR}${PREFIX}/etc/login_duo.conf ; \
	fi
	@if [ ! -f ${PREFIX}/etc/pam_duo.conf ]; then \
		${CP} -p ${STAGEDIR}${PREFIX}/etc/pam_duo.conf.sample \
		    ${STAGEDIR}${PREFIX}/etc/pam_duo.conf ; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
