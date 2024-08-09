PORTNAME=	metasploit
DISTVERSION=	6.4.7
PORTREVISION=	4
CATEGORIES=	security

MAINTAINER=	tanawts@gmail.com
COMMENT=	Exploit-Framework for Penetration-Testing
WWW=		https://metasploit.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		nmap:security/nmap \
		rubygem-actionpack70>=7.0:www/rubygem-actionpack70 \
		rubygem-activerecord70>=7.0:databases/rubygem-activerecord70 \
		rubygem-activesupport70>=7.0:devel/rubygem-activesupport70 \
		rubygem-aws-sdk-ec2>=0:devel/rubygem-aws-sdk-ec2 \
		rubygem-aws-sdk-ec2instanceconnect>=0:devel/rubygem-aws-sdk-ec2instanceconnect \
		rubygem-aws-sdk-iam>=0:devel/rubygem-aws-sdk-iam \
		rubygem-aws-sdk-s3>=0:devel/rubygem-aws-sdk-s3 \
		rubygem-aws-sdk-ssm>=0:devel/rubygem-aws-sdk-ssm \
		rubygem-bcrypt>=0:security/rubygem-bcrypt \
		rubygem-bcrypt_pbkdf>=0:security/rubygem-bcrypt_pbkdf \
		rubygem-bootsnap>=0:devel/rubygem-bootsnap \
		rubygem-bson>=0:devel/rubygem-bson \
		rubygem-bundler>=0:sysutils/rubygem-bundler \
		rubygem-chunky_png>=0:graphics/rubygem-chunky_png \
		rubygem-dnsruby>=0:dns/rubygem-dnsruby \
		rubygem-ed25519>=0:security/rubygem-ed25519 \
		rubygem-em-http-request>=0:www/rubygem-em-http-request \
		rubygem-eventmachine>=0:devel/rubygem-eventmachine \
		rubygem-faker>=0:devel/rubygem-faker \
		rubygem-faraday>=0:www/rubygem-faraday \
		rubygem-faraday-retry>=0:www/rubygem-faraday-retry \
		rubygem-faye-websocket>=0:www/rubygem-faye-websocket \
		rubygem-filesize>=0:devel/rubygem-filesize \
		rubygem-hrr_rb_ssh-ed25519>=0:security/rubygem-hrr_rb_ssh-ed25519 \
		rubygem-http-cookie>=0:www/rubygem-http-cookie \
		rubygem-irb>=0:devel/rubygem-irb \
		rubygem-jsobfu>=0:www/rubygem-jsobfu \
		rubygem-json>=0:devel/rubygem-json \
		rubygem-metasm>=0:devel/rubygem-metasm \
		rubygem-metasploit-concern>=0:security/rubygem-metasploit-concern \
		rubygem-metasploit-credential>=0:security/rubygem-metasploit-credential \
		rubygem-metasploit-model>=0:security/rubygem-metasploit-model \
		rubygem-metasploit-payloads>=2.0.166:security/rubygem-metasploit-payloads \
		rubygem-metasploit_data_models>=0:security/rubygem-metasploit_data_models \
		rubygem-metasploit_payloads-mettle>=1.0.26:security/rubygem-metasploit_payloads-mettle \
		rubygem-mqtt>=0:net/rubygem-mqtt \
		rubygem-msgpack>=0:devel/rubygem-msgpack \
		rubygem-nessus_rest>=0:security/rubygem-nessus_rest \
		rubygem-net-imap>=0:mail/rubygem-net-imap \
		rubygem-net-ldap>=0:net/rubygem-net-ldap \
		rubygem-net-smtp>=0:mail/rubygem-net-smtp \
		rubygem-net-ssh>=0:security/rubygem-net-ssh \
		rubygem-network_interface>=0:net/rubygem-network_interface \
		rubygem-nexpose>=0:security/rubygem-nexpose \
		rubygem-nokogiri>=0:textproc/rubygem-nokogiri \
		rubygem-octokit>=0:net/rubygem-octokit \
		rubygem-openssl-ccm>=0:security/rubygem-openssl-ccm \
		rubygem-openvas-omp>=0:security/rubygem-openvas-omp \
		rubygem-packetfu>=0:net/rubygem-packetfu \
		rubygem-patch_finder>=0:devel/rubygem-patch_finder \
		rubygem-pcaprub>=0:net/rubygem-pcaprub \
		rubygem-pdf-reader>=0:print/rubygem-pdf-reader \
		rubygem-pg>=0:databases/rubygem-pg \
		rubygem-puma>=0:www/rubygem-puma \
		rubygem-railties70>=7.0:www/rubygem-railties70 \
		rubygem-rasn1>=0:security/rubygem-rasn1 \
		rubygem-recog>=0:security/rubygem-recog \
		rubygem-redcarpet>=0:textproc/rubygem-redcarpet \
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
		rubygem-ruby-macho>=0:devel/rubygem-ruby-macho \
		rubygem-ruby-mysql>=0:databases/rubygem-ruby-mysql \
		rubygem-ruby_smb>=0:net/rubygem-ruby_smb \
		rubygem-rubyntlm>=0:net/rubygem-rubyntlm \
		rubygem-rubyzip>=0:archivers/rubygem-rubyzip \
		rubygem-sinatra2>=0:www/rubygem-sinatra2 \
		rubygem-sqlite3>=0:databases/rubygem-sqlite3 \
		rubygem-sshkey>=0:security/rubygem-sshkey \
		rubygem-swagger-blocks>=0:devel/rubygem-swagger-blocks \
		rubygem-thin>=0:www/rubygem-thin \
		rubygem-tzinfo>=0:devel/rubygem-tzinfo \
		rubygem-tzinfo-data>=0:devel/rubygem-tzinfo-data \
		rubygem-unix-crypt>=0:security/rubygem-unix-crypt \
		rubygem-warden>=0:devel/rubygem-warden \
		rubygem-windows_error>=0:devel/rubygem-windows_error \
		rubygem-winrm>=0:sysutils/rubygem-winrm \
		rubygem-xdr>=0:converters/rubygem-xdr \
		rubygem-xmlrpc>=0:net/rubygem-xmlrpc \
		rubygem-zeitwerk>=0:devel/rubygem-zeitwerk

USES=		cpe go:run python ruby shebangfix
CPE_VENDOR=	rapid7
USE_GITHUB=	yes
GH_ACCOUNT=	rapid7
GH_PROJECT=	metasploit-framework

SHEBANG_FILES=	data/exploits/CVE-2017-17562/build.sh \
		data/exploits/CVE-2017-17562/install-deps.sh \
		data/exploits/CVE-2017-7494/build.sh \
		data/exploits/CVE-2017-7494/install-deps.sh \
		data/exploits/CVE-2021-3156/nss_generic2.py \
		data/exploits/CVE-2021-3156/nss_u14.py \
		data/exploits/CVE-2021-3156/nss_u16.py \
		data/exploits/CVE-2021-3156/userspec_c7.py \
		data/exploits/CVE-2021-3156/userspec_generic.py \
		docker/bin/msfconsole docker/bin/msfvenom docker/entrypoint.sh \
		external/source/exploits/CVE-2020-9850/payload/loader/make.py \
		external/source/exploits/CVE-2020-9850/payload/sbx/build-threadexec.sh \
		external/source/exploits/CVE-2020-9850/payload/sbx/build-webkit.sh \
		external/source/exploits/CVE-2020-9850/payload/sbx/embed.py \
		external/source/metsvc/test.rb \
		external/source/msfJavaToolkit/compile.sh \
		external/source/msfJavaToolkit/testCompilation.rb \
		external/source/msfJavaToolkit/testKeytool.rb \
		external/source/shellcode/windows/build.sh \
		external/source/shellcode/windows/x64/build.py \
		external/source/shellcode/windows/x86/build.py \
		external/source/shellcode/windows/x86/src/hash.py \
		modules/auxiliary/admin/http/cisco_7937g_ssh_privesc.py \
		modules/auxiliary/admin/http/grafana_auth_bypass.py \
		modules/auxiliary/admin/teradata/teradata_odbc_sql.py \
		modules/auxiliary/dos/cisco/cisco_7937g_dos.py \
		modules/auxiliary/dos/cisco/cisco_7937g_dos_reboot.py \
		modules/auxiliary/dos/http/slowloris.py \
		modules/auxiliary/dos/tcp/claymore_dos.py \
		modules/auxiliary/example.py \
		modules/auxiliary/gather/get_user_spns.py \
		modules/auxiliary/gather/mikrotik_winbox_fileread.py \
		modules/auxiliary/gather/office365userenum.py \
		modules/auxiliary/scanner/http/onion_omega2_login.py \
		modules/auxiliary/scanner/http/rdp_web_login.py \
		modules/auxiliary/scanner/http/rpyc_rce.py \
		modules/auxiliary/scanner/msmail/exchange_enum.go \
		modules/auxiliary/scanner/msmail/host_id.go \
		modules/auxiliary/scanner/msmail/onprem_enum.go \
		modules/auxiliary/scanner/smb/impacket/dcomexec.py \
		modules/auxiliary/scanner/smb/impacket/secretsdump.py \
		modules/auxiliary/scanner/smb/impacket/wmiexec.py \
		modules/auxiliary/scanner/ssl/bleichenbacher_oracle.py \
		modules/auxiliary/scanner/teradata/teradata_odbc_login.py \
		modules/auxiliary/scanner/wproxy/att_open_proxy.py \
		modules/exploits/example.py \
		modules/exploits/linux/smtp/haraka.py \
		tools/dev/import-dev-keys.sh tools/dev/sign-dev-keys.sh \
		tools/dev/update_joomla_components.py \
		tools/hardware/killerbee_msfrelay.py \
		tools/modules/aws-aggregator-userdata.sh \
		test/ldap/samba-ad-run.sh \
		test/ldap/samba-ad-setup.sh
SHEBANG_LANG=	go

STRIP=
NO_ARCH=	yes
NO_ARCH_IGNORE=	template_x64_bsd.bin template_x86_bsd.bin CVE-2013-2171.bin

post-patch:
	${REINPLACE_CMD} "/rb-readline/d ; /win32api/d ; \
		/msgpack/s|, '~> 1.6.0'|| ; /nokogiri/s|, '~> 1.14.0'|| ; /octokit/s|, '~> 4.0'|| ; /sqlite3/s|, '1.6.6'|| ; /irb/s|, '~> 1.7.4'|| ; /faraday/s|, '2.7.11'||" \
		${WRKSRC}/metasploit-framework.gemspec

do-build:
	${RM} ${WRKSRC}/Gemfile.lock
	${TOUCH} ${WRKSRC}/Gemfile.lock
	${REINPLACE_CMD} "/^group :coverage/,/^end/d ; /^group :development/,/^end/d ; /^group :test/,/^end/d" \
		${WRKSRC}/Gemfile

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${PAX} -rw . ${STAGEDIR}${DATADIR}
.for f in msfconsole msfd msfdb msfrpc msfrpcd msfvenom
	${RLN} ${STAGEDIR}${DATADIR}/${f} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor

post-install:
	@${FIND} ${STAGEDIR} ! -type d | \
		${SED} 's,${STAGEDIR}${PREFIX}/,, ; /Gemfile.lock/s|^|@(,,0666) |' >> ${TMPPLIST}
	@${FIND} -ds ${STAGEDIR}${DATADIR} -type d -empty | \
		${SED} 's,${STAGEDIR}${PREFIX}/,, ; s,^,@dir ,' >> ${TMPPLIST}

.include <bsd.port.mk>
