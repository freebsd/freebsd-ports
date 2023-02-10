# -*- coding: utf-8 -*-
from setuptools import setup

setup(
    name='plumbum',
    version='%%PORTVERSION%%',
    description='Plumbum: shell combinators library',
    long_description='.. image:: https://readthedocs.org/projects/plumbum/badge/\n   :target: https://plumbum.readthedocs.io/en/latest/\n   :alt: Documentation Status\n.. image:: https://github.com/tomerfiliba/plumbum/workflows/CI/badge.svg\n   :target: https://github.com/tomerfiliba/plumbum/actions\n   :alt: Build Status\n.. image:: https://coveralls.io/repos/tomerfiliba/plumbum/badge.svg?branch=master&service=github\n   :target: https://coveralls.io/github/tomerfiliba/plumbum?branch=master\n   :alt: Coverage Status\n.. image:: https://img.shields.io/pypi/v/plumbum.svg\n   :target: https://pypi.python.org/pypi/plumbum/\n   :alt: PyPI Status\n.. image:: https://img.shields.io/pypi/pyversions/plumbum.svg\n   :target: https://pypi.python.org/pypi/plumbum/\n   :alt: PyPI Versions\n.. image:: https://img.shields.io/conda/vn/conda-forge/plumbum.svg\n   :target: https://github.com/conda-forge/plumbum-feedstock\n   :alt: Conda-Forge Badge\n.. image:: https://img.shields.io/pypi/l/plumbum.svg\n   :target: https://pypi.python.org/pypi/plumbum/\n   :alt: PyPI License\n.. image:: https://badges.gitter.im/plumbumpy/Lobby.svg\n   :alt: Join the chat at https://gitter.im/plumbumpy/Lobby\n   :target: https://gitter.im/plumbumpy/Lobby?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge\n.. image:: https://img.shields.io/badge/code%20style-black-000000.svg\n   :alt: Code styled with Black\n   :target: https://github.com/psf/black\n\n\nPlumbum: Shell Combinators\n==========================\n\nEver wished the compactness of shell scripts be put into a **real** programming language?\nSay hello to *Plumbum Shell Combinators*. Plumbum (Latin for *lead*, which was used to create\npipes back in the day) is a small yet feature-rich library for shell script-like programs in Python.\nThe motto of the library is **"Never write shell scripts again"**, and thus it attempts to mimic\nthe **shell syntax** ("shell combinators") where it makes sense, while keeping it all **Pythonic\nand cross-platform**.\n\nApart from shell-like syntax and handy shortcuts, the library provides local and remote command\nexecution (over SSH), local and remote file-system paths, easy working-directory and environment\nmanipulation, and a programmatic Command-Line Interface (CLI) application toolkit.\nNow let\'s see some code!\n\n*This is only a teaser; the full documentation can be found at*\n`Read the Docs <https://plumbum.readthedocs.io>`_\n\nCheat Sheet\n-----------\n\nBasics\n******\n\n.. code-block:: python\n\n    >>> from plumbum import local\n    >>> local.cmd.ls\n    LocalCommand(/bin/ls)\n    >>> local.cmd.ls()\n    \'build.py\\nCHANGELOG.rst\\nconda.recipe\\nCONTRIBUTING.rst\\ndocs\\nexamples\\nexperiments\\nLICENSE\\nMANIFEST.in\\nPipfile\\nplumbum\\nplumbum.egg-info\\npytest.ini\\nREADME.rst\\nsetup.cfg\\nsetup.py\\ntests\\ntranslations.py\\n\'\n    >>> notepad = local["c:\\\\windows\\\\notepad.exe"]\n    >>> notepad()                                   # Notepad window pops up\n    \'\'                                              # Notepad window is closed by user, command returns\n\nIn the example above, you can use ``local["ls"]`` if you have an unusually named executable or a full path to an executable. The ``local`` object represents your local machine. As you\'ll see, Plumbum also provides remote machines that use the same API!\nYou can also use ``from plumbum.cmd import ls`` as well for accessing programs in the ``PATH``.\n\nPiping\n******\n\n.. code-block:: python\n\n    >>> from plumbum.cmd import ls, grep, wc\n    >>> chain = ls["-a"] | grep["-v", r"\\.py"] | wc["-l"]\n    >>> print(chain)\n    /bin/ls -a | /bin/grep -v \'\\.py\' | /usr/bin/wc -l\n    >>> chain()\n    \'27\\n\'\n\nRedirection\n***********\n\n.. code-block:: python\n\n    >>> from plumbum.cmd import cat, head\n    >>> ((cat < "setup.py") | head["-n", 4])()\n    \'#!/usr/bin/env python3\\nimport os\\n\\ntry:\\n\'\n    >>> (ls["-a"] > "file.list")()\n    \'\'\n    >>> (cat["file.list"] | wc["-l"])()\n    \'31\\n\'\n\nWorking-directory manipulation\n******************************\n\n.. code-block:: python\n\n    >>> local.cwd\n    <LocalWorkdir /home/tomer/workspace/plumbum>\n    >>> with local.cwd(local.cwd / "docs"):\n    ...     chain()\n    ...\n    \'22\\n\'\n\nForeground and background execution\n***********************************\n\n.. code-block:: python\n\n    >>> from plumbum import FG, BG\n    >>> (ls["-a"] | grep[r"\\.py"]) & FG         # The output is printed to stdout directly\n    build.py\n    setup.py\n    translations.py\n    >>> (ls["-a"] | grep[r"\\.py"]) & BG         # The process runs "in the background"\n    <Future [\'/bin/grep\', \'\\\\.py\'] (running)>\n\nCommand nesting\n***************\n\n.. code-block:: python\n\n    >>> from plumbum.cmd import sudo, ifconfig\n    >>> print(sudo[ifconfig["-a"]])\n    /usr/bin/sudo /sbin/ifconfig -a\n    >>> (sudo[ifconfig["-a"]] | grep["-i", "loop"]) & FG\n    lo        Link encap:Local Loopback\n              UP LOOPBACK RUNNING  MTU:16436  Metric:1\n\nRemote commands (over SSH)\n**************************\n\nSupports `openSSH <http://www.openssh.org/>`_-compatible clients,\n`PuTTY <http://www.chiark.greenend.org.uk/~sgtatham/putty/>`_ (on Windows)\nand `Paramiko <https://github.com/paramiko/paramiko/>`_ (a pure-Python implementation of SSH2)\n\n.. code-block:: python\n\n    >>> from plumbum import SshMachine\n    >>> remote = SshMachine("somehost", user = "john", keyfile = "/path/to/idrsa")\n    >>> r_ls = remote["ls"]\n    >>> with remote.cwd("/lib"):\n    ...     (r_ls | grep["0.so.0"])()\n    ...\n    \'libusb-1.0.so.0\\nlibusb-1.0.so.0.0.0\\n\'\n\nCLI applications\n****************\n\n.. code-block:: python\n\n    import logging\n    from plumbum import cli\n\n    class MyCompiler(cli.Application):\n        verbose = cli.Flag(["-v", "--verbose"], help = "Enable verbose mode")\n        include_dirs = cli.SwitchAttr("-I", list = True, help = "Specify include directories")\n\n        @cli.switch("--loglevel", int)\n        def set_log_level(self, level):\n            """Sets the log-level of the logger"""\n            logging.root.setLevel(level)\n\n        def main(self, *srcfiles):\n            print("Verbose:", self.verbose)\n            print("Include dirs:", self.include_dirs)\n            print("Compiling:", srcfiles)\n\n    if __name__ == "__main__":\n        MyCompiler.run()\n\nSample output\n+++++++++++++\n\n::\n\n    $ python3 simple_cli.py -v -I foo/bar -Ispam/eggs x.cpp y.cpp z.cpp\n    Verbose: True\n    Include dirs: [\'foo/bar\', \'spam/eggs\']\n    Compiling: (\'x.cpp\', \'y.cpp\', \'z.cpp\')\n\nColors and Styles\n-----------------\n\n.. code-block:: python\n\n    from plumbum import colors\n    with colors.red:\n        print("This library provides safe, flexible color access.")\n        print(colors.bold | "(and styles in general)", "are easy!")\n    print("The simple 16 colors or",\n          colors.orchid & colors.underline | \'256 named colors,\',\n          colors.rgb(18, 146, 64) | "or full rgb colors",\n          \'can be used.\')\n    print("Unsafe " + colors.bg.dark_khaki + "color access" + colors.bg.reset + " is available too.")\n',
    classifiers=[
        'Development Status :: 5 - Production/Stable',
        'License :: OSI Approved :: MIT License',
        'Operating System :: Microsoft :: Windows',
        'Operating System :: POSIX',
        'Programming Language :: Python :: 3',
        'Programming Language :: Python :: 3 :: Only',
        'Programming Language :: Python :: 3.6',
        'Programming Language :: Python :: 3.7',
        'Programming Language :: Python :: 3.8',
        'Programming Language :: Python :: 3.9',
        'Programming Language :: Python :: 3.10',
        'Programming Language :: Python :: 3.11',
        'Topic :: Software Development :: Build Tools',
        'Topic :: System :: Systems Administration',
    ],
    install_requires=[
        'pywin32; platform_system == "Windows" and platform_python_implementation != "PyPy"',
    ],
    extras_require={
        'dev': [
            'paramiko',
            'psutil',
            'pytest-cov',
            'pytest-mock',
            'pytest-timeout',
            'pytest>=6.0',
        ],
        'docs': [
            'sphinx-rtd-theme>=1.0.0',
            'sphinx>=4.0.0',
        ],
        'ssh': [
            'paramiko',
        ],
    },
    packages=[
        'plumbum',
        'plumbum.cli',
        'plumbum.colorlib',
        'plumbum.commands',
        'plumbum.fs',
        'plumbum.machines',
        'plumbum.path',
    ],
)
