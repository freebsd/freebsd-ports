# New ports collection makefile for:    ourmon
# Date created: 01 May 2005
# Whom:         Charlie Schluting <manos@cs.pdx.edu>
#
# $FreeBSD$

PORTNAME=       ourmon
PORTVERSION=    2.5
PORTREVISION=    1
CATEGORIES=     net-mgmt
MASTER_SITES=   http://ourmon.cat.pdx.edu/ourmon/
DISTNAME=       ourmon25

MAINTAINER=     manos@cs.pdx.edu
COMMENT=        A libpcap-based network monitoring and anomaly detection system

BUILD_DEPENDS=  ${LOCALBASE}/lib/libpcap.a:${PORTSDIR}/net/libpcap
LIB_DEPENDS=    gd:$(PORTSDIR)/graphics/gd
RUN_DEPENDS=    rrdtool:$(PORTSDIR)/databases/rrdtool

#IS_INTERACTIVE= yes
WRKSRC=         ${WRKDIR}/mrourmon
USE_PERL5=	yes
NO_INSTALL_MANPAGES=	yes
#NO_PACKAGE=	yes
NO_BUILD=	yes

# where to install ourmon and also
# where we build the ourmon runtime-script with configure.pl
# note: we use the work directory simply for unpacking

# make simply states assumptions, unpacks the system, and puts it in PREFIX
pre-build:
	@${ECHO_MSG} "install dir is PREFIX=\"${PREFIX}/mrourmon\""
	@${ECHO_MSG} "We do not install apache or some other web server for you.
	@${ECHO_MSG} "You should know where your apache docs directory is before make install."
	@${ECHO_MSG} "You should also know which network interface you want ourmon to use."
	@${ECHO_MSG}
	@${ECHO_MSG} "Ourmon may be installed on one CPU or two.  If you"
	@${ECHO_MSG} "are only installing the front-end probe, you do"
	@${ECHO_MSG} "not need Apache, hence we do not install it."
	@${ECHO_MSG} "If you are installing the back-end graphics engine"
	@${ECHO_MSG} "(which needs a web server) do install Apache first, and note"
	@${ECHO_MSG} "where the htdocs web directory lives.  You will need"
	@${ECHO_MSG} "that for ourmon configuration.  If you simply"
	@${ECHO_MSG} "want to install ourmon with both front-end and back-end"
	@${ECHO_MSG} "on one CPU, then install Apache first on that machine."
	@${ECHO_MSG}

pre-install:
.if exists(${PREFIX}/etc/ourmon.conf)
	${MV} ${PREFIX}/etc/ourmon.conf ${PREFIX}/etc/ourmon.conf.old
.endif
	$(CP) -R ${WRKSRC} ${PREFIX}

# make install compiles and configures the system installing
# all binaries in the local PREFIX/bin as well as asking
# the user if he/she wants to install system start scripts
# and modify /etc/crontab

do-install:
	cd ${PREFIX}/mrourmon && ${PERL5} configure.pl ${PREFIX}

post-install:
	@${ECHO_MSG} "Ourmon is installed in ${PREFIX}"
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
