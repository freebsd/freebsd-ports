# Created by: Sergei Vyshenski <svysh@pn.sinp.msu.ru>
# $FreeBSD$

PORTNAME=	openxpki
PORTVERSION=	0.9.1389
PORTREVISION=	2
CATEGORIES=	security perl5
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.9.1300
PKGNAMEPREFIX=	p5-
DISTNAME=	OpenXPKI-${PORTVERSION}
DIST_SUBDIR=	openxpki

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Perl based trustcenter software for PKI: core for server

LICENSE=	ART20

BUILD_DEPENDS=	\
	p5-Workflow>=0.31:${PORTSDIR}/devel/p5-Workflow \
	p5-CGI-Session>=0:${PORTSDIR}/www/p5-CGI-Session \
	p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate \
	p5-Locale-libintl>=0:${PORTSDIR}/devel/p5-Locale-libintl \
	p5-perl-ldap>=0:${PORTSDIR}/net/p5-perl-ldap \
	p5-Regexp-Common>=0:${PORTSDIR}/textproc/p5-Regexp-Common \
	p5-Text-CSV_XS>=0:${PORTSDIR}/textproc/p5-Text-CSV_XS \
	p5-XML-Filter-XInclude>=0:${PORTSDIR}/textproc/p5-XML-Filter-XInclude \
	p5-XML-SAX-Writer>=0:${PORTSDIR}/textproc/p5-XML-SAX-Writer \
	p5-XML-Validator-Schema>=0:${PORTSDIR}/textproc/p5-XML-Validator-Schema \
	p5-Net-Server>=0:${PORTSDIR}/net/p5-Net-Server \
	p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod \
	p5-Test-Pod-Coverage>=0:${PORTSDIR}/devel/p5-Test-Pod-Coverage \
	p5-Net-IP>=0:${PORTSDIR}/net-mgmt/p5-Net-IP \
	p5-Class-Std>=0:${PORTSDIR}/devel/p5-Class-Std \
	p5-Mail-RFC822-Address>=0:${PORTSDIR}/mail/p5-Mail-RFC822-Address \
	p5-Proc-ProcessTable>=0:${PORTSDIR}/devel/p5-Proc-ProcessTable \
	p5-Sys-SigAction>=0:${PORTSDIR}/devel/p5-Sys-SigAction \
	p5-Data-Password>=0:${PORTSDIR}/security/p5-Data-Password \
	p5-RT-Client-REST>=0:${PORTSDIR}/www/p5-RT-Client-REST \
	p5-Data-Serializer>=0:${PORTSDIR}/devel/p5-Data-Serializer \
	p5-IPC-ShareLite>=0:${PORTSDIR}/devel/p5-IPC-ShareLite \
	p5-DateTime-Format-DateParse>=0:${PORTSDIR}/devel/p5-DateTime-Format-DateParse \
	p5-IO-Prompt>=0:${PORTSDIR}/devel/p5-IO-Prompt
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_OPENSSL=	yes
USE_PERL5=	configure
USES=		gmake perl5
WITH_OPENSSL_BASE=	yes

USERS=	openxpki
GROUPS=	openxpki

OPTIONS_DEFINE=	DEVELOPER GRAPHVIZ
DEVELOPER_DESC=	Install development tools for OpenXPKI?
GRAPHVIZ_DESC=	With graphical visualization of workflows?
# If DEVELOPER is checked, then docbook, Java and Xorg libraries are installed.
# They are needed only if you plan to fetch development svn snapshot,
# then edit XML prototypes for collection of OpenXPKI guides, and then
# compile the collection into HTML or PDF forms.
# If you want to read OpenXPKI documentation, these tools are not needed.
# Just visit http://www.openxpki.org/docs/

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEVELOPER}
RUN_DEPENDS+=	${LOCALBASE}/bin/fop:${PORTSDIR}/textproc/fop \
		${LOCALBASE}/bin/xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/html/chunk.xsl:${PORTSDIR}/textproc/docbook-xsl \
		${LOCALBASE}/share/java/jai/lib/libmlib_jai.so:${PORTSDIR}/java/jai
.endif
.if ${PORT_OPTIONS:MGRAPHVIZ}
RUN_DEPENDS+=	${LOCALBASE}/bin/dot:${PORTSDIR}/graphics/graphviz \
		${LOCALBASE}/bin/imgsize:${PORTSDIR}/graphics/p5-Image-Size
.endif

.include <bsd.port.pre.mk>

# this port needs OpenSSL 0.9.8+, but does not yet compile with OpenSSL 1.0.0+
# FreeBSD 7,8,9 have base OpenSSL 0.9.8 which is good
# FreeBSD 10 has base OpenSSL 1.0+ which is bad
# OpenSSL from port now has version 1.0+ only
.if ${OSVERSION} >= 1000000
IGNORE=	needs OpenSSL 0.9.8+, but does not yet compile with OpenSSL 1.0.0+
.endif

.include <bsd.port.post.mk>
