# New ports collection makefile for:	cfengine v3
# Date created:		February 2, 2009
# Whom:			jrhett@netconsonance.com
#
# $FreeBSD$
#

PORTNAME=	cfengine
PORTVERSION=	3.0.1
DISTVERSION=	3.0.1a7
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cfengine.org/downloads/

MAINTAINER=	jrhett@netconsonance.com
COMMENT=	A systems administration tool for networks
LATEST_LINK=	cfengine3

USE_RC_SUBR=	cf-execd cf-serverd

WITH_BDB_VER?=	47
USE_BDB=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
BUILD_DEPENDS=
EXAMPLESDIR=	${PREFIX}/share/examples/cfengine3
DOCSDIR=	${PREFIX}/share/doc/cfengine3
CONFIGURE_ARGS=	--docdir=${DOCSDIR} \
		--htmldir=${DOCSDIR}/html \
		--with-berkeleydb=${LOCALBASE}

CONFIGURE_ENV+=	BERKELEY_DB_CFLAGS=-I${BDB_INCLUDE_DIR} \
		BERKELEY_DB_LDFLAGS=-L${BDB_LIB_DIR} \
		BERKELEY_DB_LIB=-l${BDB_LIB_NAME}

OPTIONS=        PCRE	"Enable Perl-compatible regular expressions"		on
.include <bsd.port.pre.mk>

.if defined(WITH_PCRE)
BUILD_DEPENDS+= ${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+= --with-pcre=${LOCALBASE}
.endif

MAN8=   cf-agent.8   cf-key.8      cf-monitord.8   \
        cf-report.8  cf-serverd.8  cf-execd.8      \
        cf-know.8    cf-promise.8  cf-runagent.8

.if !defined(NOPORTDOCS)
INFO=		cf3-reference
.endif

post-patch:
		@${REINPLACE_CMD} -e '/^pkgdatadir/s!=.*!= ${EXAMPLESDIR}!'\
				  ${WRKSRC}/inputs/Makefile.in

		@${REINPLACE_CMD} -e '/^docdir/s!=.*!= @docdir@!'\
				  ${WRKSRC}/tests/file_masters/Makefile.in \
				  ${WRKSRC}/tests/units/Makefile.in

		@${REINPLACE_CMD} -e '/^htmldir/s!=.*!= @htmldir@!'\
				  ${WRKSRC}/docs/Makefile.in

.include <bsd.port.post.mk>
