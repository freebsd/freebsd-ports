# New ports collection makefile for:   flowd
# Date created:        9 October 2004
# Whom:                Janos Mohacsi <janos.mohacsi@bsd.hu>
#
# $FreeBSD$
#

PORTNAME=	flowd
PORTVERSION=	0.9.1
PORTREVISION=	2
CATEGORIES=	net-mgmt ipv6
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		http://www2.mindrot.org/files/flowd/

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	The flowd is a small, fast, and secure NetFlow collector

OPTIONS=	PERL	"Install flowd perl module" on \
		PYTHON	"Install flowd Python support" off

.include <bsd.port.options.mk>

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var
USE_GMAKE=	yes
USE_RC_SUBR=	flowd
MAN8=		flowd.8 flowd-reader.8
MAN5=		flowd.conf.5
PORTDOCS=	README INSTALL
FLOWD_USER=	_flowd
USERS=		${FLOWD_USER}
GROUPS=		${FLOWD_USER}

.if defined(WITH_PERL)
USE_PERL5=	yes
PLIST_SUB+=	WITH_PERL=""
MAN3=		Flowd.3
.else
PLIST_SUB+=	WITH_PERL="@comment "
.endif

.if defined(WITH_PYTHON)
USE_PYTHON=	yes
PLIST_SUB+=	WITH_PYTHON=""
INSTALLS_EGGINFO=	yes
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
	${REINPLACE_CMD} -i '' -e 's|/usr/bin/perl|${PERL}|' \
		${WRKSRC}/tools/flowinsert.pl \
		${WRKSRC}/tools/wormsuspects.pl

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.if defined(WITH_PERL)
	cd ${WRKSRC}/Flowd-perl && \
	${PERL} Makefile.PL INSTALLSITEMAN3DIR=${MAN3PREFIX}/man/man3 PREFIX=${PREFIX} && \
	${GMAKE} && \
	${GMAKE} install;
	-@${RM} -f ${PREFIX}/lib/perl5/${PERL_VERSION}/${PERL_ARCH}/perllocal.pod
.endif

.if defined(WITH_PYTHON)
	cd ${WRKSRC} && \
	${PYTHON_CMD} setup.py build && \
	${PYTHON_CMD} setup.py install
.endif

.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	@( cd ${WRKSRC}/tools && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}/ )
.endif

.include <bsd.port.mk>
