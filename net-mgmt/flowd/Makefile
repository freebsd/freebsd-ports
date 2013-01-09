# Created by: Janos Mohacsi <janos.mohacsi@bsd.hu>
# $FreeBSD$

PORTNAME=	flowd
PORTVERSION=	0.9.1
PORTREVISION=	2
CATEGORIES=	net-mgmt ipv6
MASTER_SITES=	GOOGLE_CODE \
		http://www2.mindrot.org/files/flowd/

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Small, fast, and secure NetFlow collector

OPTIONS_DEFINE=	PERL PYTHON
OPTIONS_DEFAULT=PERL

PERL_DESC=	Install flowd perl module
PYTHON_DESC=	Install flowd Python support

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

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPERL}
USE_PERL5=	yes
PLIST_SUB+=	PERL=""
MAN3=		Flowd.3
.else
PLIST_SUB+=	PERL="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
PLIST_SUB+=	PYTHON=""
INSTALLS_EGGINFO=	yes
.else
PLIST_SUB+=	PYTHON="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e "s;%%FLOWD_USER%%;${FLOWD_USER};g" \
		${WRKSRC}/flowd.h
	${REINPLACE_CMD} -i '' -e 's|/usr/bin/perl|${PERL}|' \
		${WRKSRC}/tools/flowinsert.pl \
		${WRKSRC}/tools/wormsuspects.pl

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MPERL}
	cd ${WRKSRC}/Flowd-perl && \
	${PERL} Makefile.PL INSTALLSITEMAN3DIR=${MAN3PREFIX}/man/man3 PREFIX=${PREFIX} && \
	${GMAKE} && \
	${GMAKE} install;
	-@${RM} -f ${PREFIX}/lib/perl5/${PERL_VERSION}/${PERL_ARCH}/perllocal.pod
.endif

.if ${PORT_OPTIONS:MPYTHON}
	cd ${WRKSRC} && \
	${PYTHON_CMD} setup.py build && \
	${PYTHON_CMD} setup.py install
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	@( cd ${WRKSRC}/tools && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}/ )
.endif

.include <bsd.port.mk>
