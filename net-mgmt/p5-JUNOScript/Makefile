# New ports collection makefile for:	JUNOScript
# Date created:		13. March 2002
# Whom:			jesper@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		JUNOScript
PORTVERSION=		5.3R2.4
PORTREVISION=		2
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_LOCAL} \
			http://e.wheel.dk/~jesper/
MASTER_SITE_SUBDIR=	jesper
PKGNAMEPREFIX=		p5-
DISTNAME=		junoscript-perl-${PORTVERSION}-domestic

MAINTAINER=		jesper@FreeBSD.org

PERL_BASE=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
LIB_DEPENDS=	expat.4:${PORTSDIR}/textproc/expat2 \
		xml2:${PORTSDIR}/textproc/libxml2 \
		xslt:${PORTSDIR}/textproc/libxslt
BUILD_DEPENDS=	${PERL_BASE}/${PERL_ARCH}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib \
		${PERL_BASE}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${PERL_BASE}/Convert/ASN1.pm:${PORTSDIR}/converters/p5-Convert-ASN1 \
		${PERL_BASE}/Convert/PEM.pm:${PORTSDIR}/converters/p5-Convert-PEM \
		${PERL_BASE}/Convert/ASCII/Armor.pm:${PORTSDIR}/converters/p5-Convert-ASCII-Armour \
		${PERL_BASE}/Class/Loader.pm:${PORTSDIR}/devel/p5-Class-Loader \
		${PERL_BASE}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
		${PERL_BASE}/${PERL_ARCH}/IO/Tty.pm:${PORTSDIR}/devel/p5-IO-Tty \
		${PERL_BASE}/Parse/Yapp.pm:${PORTSDIR}/devel/p5-Parse-Yapp \
		${PERL_BASE}/Sort/Versions.pm:${PORTSDIR}/devel/p5-Sort-Versions \
		${PERL_BASE}/${PERL_ARCH}/String/CRC32.pm:${PORTSDIR}/devel/p5-String-CRC32 \
		${PERL_BASE}/${PERL_ARCH}/Math/Pari.pm:${PORTSDIR}/math/p5-Math-Pari \
		${PERL_BASE}/${PERL_ARCH}/Math/GMP.pm:${PORTSDIR}/math/p5-Math-GMP \
		${PERL_BASE}/Data/Buffer.pm:${PORTSDIR}/misc/p5-Data-Buffer \
		${PERL_BASE}/Net/FTP.pm:${PORTSDIR}/net/p5-Net \
		${PERL_BASE}/URI.pm:${PORTSDIR}/net/p5-URI \
		${PERL_BASE}/Digest/BubbleBabble.pm:${PORTSDIR}/security/p5-Digest-BubbleBabble \
		${PERL_BASE}/Crypt/DSA.pm:${PORTSDIR}/security/p5-Crypt-DSA \
		${PERL_BASE}/Crypt/DH.pm:${PORTSDIR}/security/p5-Crypt-DH \
		${PERL_BASE}/${PERL_ARCH}/Crypt/DES.pm:${PORTSDIR}/security/p5-Crypt-DES \
		${PERL_BASE}/Crypt/DES_EDE3.pm:${PORTSDIR}/security/p5-Crypt-DES_EDE3 \
		${PERL_BASE}/Crypt/CBC.pm:${PORTSDIR}/security/p5-Crypt-CBC \
		${PERL_BASE}/${PERL_ARCH}/Crypt/Blowfish.pm:${PORTSDIR}/security/p5-Crypt-Blowfish \
		${PERL_BASE}/Crypt/Primes.pm:${PORTSDIR}/security/p5-Crypt-Primes \
		${PERL_BASE}/Crypt/Random.pm:${PORTSDIR}/security/p5-Crypt-Random \
		${PERL_BASE}/Crypt/RSA.pm:${PORTSDIR}/security/p5-Crypt-RSA \
		${PERL_BASE}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${PERL_BASE}/Digest/HMAC.pm:${PORTSDIR}/security/p5-Digest-HMAC \
		${PERL_BASE}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		openssl:${PORTSDIR}/security/openssl \
		${PERL_BASE}/${PERL_ARCH}/Net/SSLeay.pm:${PORTSDIR}/security/p5-Net-SSLeay \
		${PERL_BASE}/Tie/EncryptedHash.pm:${PORTSDIR}/security/p5-Tie-EncryptedHash \
		gtkdoc-scan:${PORTSDIR}/textproc/gtk-doc \
		${PERL_BASE}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${PERL_BASE}/XML/Perl2SAX.pm:${PORTSDIR}/textproc/p5-libxml \
		${PERL_BASE}/XML/DOM.pm:${PORTSDIR}/textproc/p5-XML-DOM \
		${PERL_BASE}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${PERL_BASE}/HTML/Tagset.pm:${PORTSDIR}/www/p5-HTML-Tagset \
		${PERL_BASE}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${PERL_BASE}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${PERL_BASE}/Net/SSH/Perl.pm:${PORTSDIR}/net/p5-Net-SSH-Perl
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/junoscript-perl-${PORTVERSION}

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		JUNOS::Access.3 \
		JUNOS::Access::stubs.3 \
		JUNOS::Access::ssl.3 \
		JUNOS::Methods.3 \
		JUNOS::Access::xnm.3 \
		JUNOS::DOM::Parser.3 \
		JUNOS::Access::clear_text.3 \
		JUNOS::Access::telnet.3 \
		JUNOS::Access::rsh.3 \
		JUNOS::Response.3 \
		JUNOS::Trace.3 \
		JUNOS::Access::ssh.3 \
		JUNOS::Device.3

.include <bsd.port.mk>
