# Created by: Yonatan <onatan@gmail.com>
# $FreeBSD$

PORTNAME=	metasploit
PORTVERSION=	5.0.64
CATEGORIES=	security

MAINTAINER=	tanawts@gmail.com
COMMENT=	Exploit-Framework for Penetration-Testing

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	nmap:security/nmap \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		rubygem-activerecord4>=4.2.6:databases/rubygem-activerecord4 \
		rubygem-activesupport4>=4.2.6:devel/rubygem-activesupport4 \
		rubygem-actionpack4>=4.2.6:www/rubygem-actionpack4 \
		rubygem-bcrypt>=0:security/rubygem-bcrypt \
		rubygem-bundler>=0:sysutils/rubygem-bundler \
		rubygem-jsobfu>=0:www/rubygem-jsobfu \
		rubygem-json>=0:devel/rubygem-json \
		rubygem-metasm>=0:devel/rubygem-metasm \
		rubygem-metasploit-aggregator>=0:security/rubygem-metasploit-aggregator \
		rubygem-metasploit-concern>=0:security/rubygem-metasploit-concern \
		rubygem-metasploit-credential>=0:security/rubygem-metasploit-credential \
		rubygem-metasploit_data_models>=3.0.10_2:security/rubygem-metasploit_data_models \
		rubygem-metasploit-model>=0:security/rubygem-metasploit-model \
		rubygem-metasploit-payloads>=1.3.83:security/rubygem-metasploit-payloads \
		rubygem-metasploit_payloads-mettle>=0.5.16:security/rubygem-metasploit_payloads-mettle \
		rubygem-msgpack>=0:devel/rubygem-msgpack \
		rubygem-network_interface>=0:net/rubygem-network_interface \
		rubygem-rubyntlm>=0:net/rubygem-rubyntlm \
		rubygem-nokogiri>=0:textproc/rubygem-nokogiri \
		rubygem-packetfu>=0:net/rubygem-packetfu \
		rubygem-pcaprub>=0:net/rubygem-pcaprub \
		rubygem-pg0>=0:databases/rubygem-pg0 \
		rubygem-railties4>=4.2.6:www/rubygem-railties4 \
		rubygem-recog>=0:security/rubygem-recog \
		rubygem-openssl-ccm>=0:security/rubygem-openssl-ccm \
		rubygem-octokit>=0:net/rubygem-octokit \
		rubygem-redcarpet>=0:textproc/rubygem-redcarpet \
		rubygem-patch_finder>=0:devel/rubygem-patch_finder \
		rubygem-thin>=0:www/rubygem-thin \
		rubygem-sinatra1>=0:www/rubygem-sinatra1 \
		rubygem-warden>=0:devel/rubygem-warden\
		rubygem-em-http-request>=0:www/rubygem-em-http-request \
		rubygem-tzinfo-data>=0:devel/rubygem-tzinfo-data \
		rubygem-sshkey>=0:security/rubygem-sshkey \
		rubygem-bit-struct>=0:devel/rubygem-bit-struct \
		rubygem-windows_error>=0:devel/rubygem-windows_error \
		rubygem-xmlrpc>=0:net/rubygem-xmlrpc \
		rubygem-pdf-reader>=0:print/rubygem-pdf-reader \
		rubygem-ruby-macho>=0:devel/rubygem-ruby-macho \
		rubygem-dnsruby>=0:dns/rubygem-dnsruby \
		rubygem-mqtt>=0:net/rubygem-mqtt \
		rubygem-net-ssh>=0:security/rubygem-net-ssh \
		rubygem-ed25519>=0:security/rubygem-ed25519 \
		rubygem-bcrypt_pbkdf>=0:security/rubygem-bcrypt_pbkdf \
		rubygem-ruby_smb>=0:net/rubygem-ruby_smb \
		rubygem-rex-arch>=0:security/rubygem-rex-arch \
		rubygem-rex-bin_tools>=0:security/rubygem-rex-bin_tools \
		rubygem-rex-core>=0:security/rubygem-rex-core \
		rubygem-rex-encoder>=0:security/rubygem-rex-encoder \
		rubygem-rex-exploitation>=0:security/rubygem-rex-exploitation \
		rubygem-rex-java>=0:security/rubygem-rex-java \
		rubygem-rex-mime>=0:security/rubygem-rex-mime \
		rubygem-rex-nop>=0:security/rubygem-rex-nop \
		rubygem-rex-ole>=0:security/rubygem-rex-ole \
		rubygem-rex-powershell>=0:security/rubygem-rex-powershell \
		rubygem-rex-random_identifier>=0:security/rubygem-rex-random_identifier \
		rubygem-rex-registry>=0:security/rubygem-rex-registry \
		rubygem-rex-rop_builder>=0:security/rubygem-rex-rop_builder \
		rubygem-rex-socket>=0:security/rubygem-rex-socket \
		rubygem-rex-sslscan>=0:security/rubygem-rex-sslscan \
		rubygem-rex-struct2>=0:security/rubygem-rex-struct2 \
		rubygem-rex-text>=0:security/rubygem-rex-text \
		rubygem-rex-zip>=0:security/rubygem-rex-zip \
		rubygem-rubyzip>=0:archivers/rubygem-rubyzip \
		rubygem-sqlite3>=0:databases/rubygem-sqlite3 \
		rubygem-tzinfo>=0:devel/rubygem-tzinfo \
		rubygem-filesize>=0:devel/rubygem-filesize \
		rubygem-openvas-omp>=0:security/rubygem-openvas-omp \
		rubygem-nessus_rest>=0:security/rubygem-nessus_rest \
		rubygem-nexpose>=0:security/rubygem-nexpose \
		rubygem-xdr>=0:converters/rubygem-xdr \
		rubygem-faker>=0:devel/rubygem-faker \
		rubygem-concurrent-ruby>=0:devel/rubygem-concurrent-ruby \
		rubygem-aws-sdk-s3>=0:devel/rubygem-aws-sdk-s3 \
		rubygem-aws-sdk-ec2>=0:devel/rubygem-aws-sdk-ec2 \
		rubygem-aws-sdk-iam>=0:devel/rubygem-aws-sdk-iam \
		rubygem-faye-websocket>=0:www/rubygem-faye-websocket \
		rubygem-eventmachine>=0:devel/rubygem-eventmachine

SCRIPTS=	msfconsole msfd msfdb msfrpc msfrpcd msfvenom

USE_GITHUB=	yes
GH_ACCOUNT=	rapid7
GH_PROJECT=	metasploit-framework

NO_ARCH=	yes
NO_ARCH_IGNORE=	template_x64_bsd.bin template_x86_bsd.bin CVE-2013-2171.bin
STRIP=

USES=		python shebangfix
USE_RUBY=	yes
SHEBANG_FILES=	data/exploits/CVE-2017-17562/build.sh \
		data/exploits/CVE-2017-17562/install-deps.sh \
		data/exploits/CVE-2017-7494/build.sh \
		data/exploits/CVE-2017-7494/install-deps.sh \
		docker/entrypoint.sh \
		external/source/shellcode/windows/build.sh \
		external/source/msfJavaToolkit/compile.sh \
		external/source/msfJavaToolkit/testKeytool.rb \
		external/source/msfJavaToolkit/testCompilation.rb \
		external/source/metsvc/test.rb \
		docker/bin/msfvenom \
		docker/bin/msfconsole \
		modules/auxiliary/dos/http/slowloris.py \
		modules/auxiliary/dos/tcp/claymore_dos.py \
		modules/auxiliary/gather/office365userenum.py \
		modules/auxiliary/scanner/smb/impacket/dcomexec.py \
		modules/auxiliary/scanner/smb/impacket/secretsdump.py \
		modules/auxiliary/scanner/smb/impacket/wmiexec.py \
		modules/auxiliary/scanner/ssl/bleichenbacher_oracle.py \
		modules/auxiliary/scanner/wproxy/att_open_proxy.py \
		tools/dev/import-dev-keys.sh \
		tools/dev/sign-dev-keys.sh \
		tools/hardware/killerbee_msfrelay.py \
		tools/modules/aws-aggregator-userdata.sh

post-patch:
	${REINPLACE_CMD} 's,git ls-files,find . ! -type d | sed "s|^./||", ; \
		/rb-readline/d' \
		${WRKSRC}/metasploit-framework.gemspec
	${REINPLACE_CMD} "/pg/s|, '~> 0.20'||; \
		/concurrent-ruby/s|,'1.0.5'||; \
		/faraday/s|, '<= 0.17.0'||; \
		/bcrypt/s|, '3.1.12'||" ${WRKSRC}/metasploit-framework.gemspec

do-build:
	${RM} ${WRKSRC}/Gemfile.lock
	${TOUCH} ${WRKSRC}/Gemfile.lock
	${REINPLACE_CMD} "/^group :coverage/,/^end/d ; /^group :development/,/^end/d ; /^group :test/,/^end/d ; /git:/d ; /sqlite3/s|, '~>1.3.0'||" \
		${WRKSRC}/Gemfile

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${PAX} -rw . ${STAGEDIR}${DATADIR}
.for f in ${SCRIPTS}
	${RLN} ${STAGEDIR}${DATADIR}/${f} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor

post-install:
	@${FIND} ${STAGEDIR} ! -type d | \
		${SED} 's,${STAGEDIR}${PREFIX}/,, ; /Gemfile.lock/s|^|@(,,0666) |' >> ${TMPPLIST}
	@${FIND} -ds ${STAGEDIR}${DATADIR} -type d -empty | \
		${SED} 's,${STAGEDIR}${PREFIX}/,, ; s,^,@dir ,' >> ${TMPPLIST}

.include <bsd.port.mk>
