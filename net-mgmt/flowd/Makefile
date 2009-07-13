# New ports collection makefile for:   flowd
# Date created:        9 October 2004
# Whom:                Janos Mohacsi <janos.mohacsi@bsd.hu>
#
# $FreeBSD$
#

PORTNAME=	flowd
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	net-mgmt ipv6
MASTER_SITES=	http://www2.mindrot.org/files/flowd/

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	The flowd is a small, fast and secure NetFlow collector

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var
USE_GMAKE=	yes
USE_RC_SUBR=	flowd
MAN8=		flowd.8 flowd-reader.8
MAN5=		flowd.conf.5
PORTDOCS=	README INSTALL
FLOWD_USER?=	_flowd

.if defined(WITH_PERL)
USE_PERL5=	yes
PLIST_SUB+=	WITH_PERL=""
#MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
#MAN3=		Flowd.3
BROKEN=		Incomplete pkg-plist
.else
PLIST_SUB+=	WITH_PERL="@comment "
.endif

.if defined(WITH_PYTHON)
USE_PYTHON=	yes
PLIST_SUB+=	WITH_PYTHON=""
BROKEN=		Incomplete pkg-plist
.else
PLIST_SUB+=	WITH_PYTHON="@comment "
.endif

pre-extract:
	@${ECHO_MSG} ""
.if defined(WITH_PERL)
	@${ECHO_MSG} "Build with perl bindings."
.else
	@${ECHO_MSG} "You can enable perl bindings by defining WITH_PERL"
.endif
	@${ECHO_MSG} ""
.if defined(WITH_PYTHON)
	@${ECHO_MSG} "Build with Python bindings."
.else
	@${ECHO_MSG} "You can enable Python bindings by defining WITH_PYTHON."
.endif

post-patch:
	@${REINPLACE_CMD} -e "s;%%FLOWD_USER%%;${FLOWD_USER};g" \
		${WRKSRC}/flowd.h

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.if defined(WITH_PERL)
	cd ${WRKSRC}/Flowd-perl && \
	${PERL} Makefile.PL  && \
	${GMAKE} && \
	${GMAKE} install
.endif

.if defined(WITH_PYTHON)
	cd ${WRKSRC} && \
	${PYTHON_CMD} setup.py build && \
	${PYTHON_CMD} setup.py install
.endif

	FLOWD_USER=${FLOWD_USER} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
