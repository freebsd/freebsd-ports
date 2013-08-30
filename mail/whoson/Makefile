# Created by: Sergey Matveychuk <sem@FreeBSD.org>
# $FreeBSD$

PORTNAME=	whoson
PORTVERSION=	2.05
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Implementation of `WHO iS ONline' protocol

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-config=${PREFIX}/etc/whoson.conf
USE_LDCONFIG=	yes

USE_RC_SUBR=	whoson

MAN3=		whoson.3 wso_login.3 wso_logout.3 wso_query.3 wso_version.3
MAN5=		whoson.conf.5
MAN8=		whoson.8 whosond.8

PORTDOCS=	README ChangeLog

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
